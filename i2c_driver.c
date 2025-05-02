
				/*---------------------------I2C byte write frame-------------------------*/
				/* _______________________________________________________________________*/
				/*|  start	 |7 bit		    |	  |8 bit   |	 |write	|	  |stop		 |*/
				/*|condition |slave add	  	| ACK |memory  | ACK |8 bit	| ACK |condition |*/
				/*|__________|"write" opern	|_____|address |_____| data	|_____|__________|*/



/*-------------------------------------------I2C byte read frame------------------------------------------*/
/* ________________________________________________________________________________________________________	*/
/*|  start	 |7 bit		      |	    |8 bit   |	   |strat	    |7 bit      |	  |  read     |  no |  stop	   |*/
/*|condition |slave add		  | ACK |memory  | ACK |condition	|slave add  | ACK |8 bit data | ACK |condition |*/
/*|__________|"write" opern   |_____|address |_____|____________|with "read"|_____|from slave |_____|__________|*/

#include"header.h"
extern void          _nop_     (void);
sbit SDA=P3^6;
sbit SCL=P3^7;
/*---------------------------------------i2c start------------------------------------*/
void i2c_start()
{
 SCL=1;
 SDA=1;
 SDA=0;
}
/*---------------------------------------i2c stop-------------------------------------*/
void i2c_stop()
{
 SCL=0;
 SDA=0;
 SCL=1;
 SDA=1;
}
/*---------------------------------------i2c write------------------------------------*/
void i2c_write(u_8 byt)
{
 s_8 i;
 for(i=7;i>=0;i--)
 {
  SCL=0;
  SDA=((byt>>i)&1);
  SCL=1;
 }
}
/*--------------------------------------i2c read--------------------------------------*/
u_8 i2c_read(void)
{
u_8 temp=0;
 s_8 i;
 for(i=7;i>=0;i--)
 {
  SCL=1;
  if(SDA==1)
  temp=((1<<i)|temp);
  SCL=0;
 }
 return temp;
}
/*----------------------------------------i2c ack----------------------------------------*/
void i2c_ack()
{
  SCL=0;
  SDA=1;
  SCL=1;
  _nop_();
  _nop_();
  _nop_();
  _nop_();
 		// if(SDA==0)
 		// {
 		 SCL=0;
 		// return 0;
//  		// }
//  			 else
//   			{
//  			 SCL=0;
//  			 return 1;
//  			 }
 }
/*----------------------------------------i2c nack------------------------------*/
void i2c_nack(void)
{
SCL=0;
SDA=1;
SCL=1;
}
/*----------------------------------------i2c byte write frame------------------------------*/
void i2c_write_frame(u_8 sa,u_8 mr,u_8 d)
{
 i2c_start();
 i2c_write(sa);
 i2c_ack();
 i2c_write(mr);
 i2c_ack();
 i2c_write(d);
 i2c_ack();
 i2c_stop();
}
/*----------------------------------------i2c byte write frame------------------------------*/
u_8 i2c_read_frame(u_8 sa,u_8 mr)
{
 u_8 temp;
 i2c_start();
 i2c_write(sa);
 i2c_ack();
 i2c_write(mr);
 i2c_ack();
 i2c_start();
 i2c_write(sa|1);
 i2c_ack();
 temp=i2c_read();
 i2c_nack();
 i2c_stop();
 return temp;
}
