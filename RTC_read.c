#include"header.h"
u_8 info[21],h,m;
void RTC_read()
{
	bit b;
	h=i2c_read_frame(0xD0,0x2);//read hours
  m=i2c_read_frame(0xD0,0x1);//read min

	b=((h>>5)&1);//checking AM/PM bit
	
	if(b==1){h=(h-0x60);  info[5]='P';  info[6]='M';  info[7]=' '; }
	else	{h=(h-0x40);  info[5]='A';  info[6]='M';  info[7]=' '; }

  info[0]=((h/16)+48);
	info[1]=((h%16)+48); 
	info[2]=':';	 
	info[3]=(m/16)+48;   
	info[4]=((m%16)+48);
}