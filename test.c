#include"header.h"
u_8 mloc[]={0x00,0x12,0x24,0x36,0x48,0x5a,0x6c,0x7e,0x90,0xa2,0xb4,0xc6,0xd8,
						0xea,0xfc,0x10e,0x120,0x132,0x144,0x156,0x168,0x17a,0x18c,0x19e,0x1b0};
u_8 info[18];
u_8 c=0;
float Temperature;
s_16 th1;
void main()
{
 u_8 h,m,n,i=0x00,temp=0; 
 u_16 adcip,j;
	float f;
 bit b;
 bit flg=0;
 lcd_init();  uart_init();  lcd_cmd(0x0c); exintr_en(); 	temp_init();
//  i2c_write_frame(0xD0,0x2,0x51);//hr
//  i2c_write_frame(0xD0,0x1,0x11);//min
//  i2c_write_frame(0xD0,0x0,0x00); //sec
 while(1)
 {
   h=i2c_read_frame(0xD0,0x2);
   m=i2c_read_frame(0xD0,0x1);
//   s=i2c_read_frame(0xD0,0x0);
/*-----------------------------------hours-------------------------------------*/
	b=((h>>5)&1);
	if(b==1){h=(h-0x60);  info[5]='P';  info[6]='M';  info[7]=' '; }
	else		{h=(h-0x40);  info[5]='A';  info[6]='M';  info[7]=' '; }
/*---------------------------------------------------------|-------------------------------------*/
    info[0]=((h/16)+48); info[1]=((h%16)+48); info[2]=':';	 info[3]=(m/16)+48;   info[4]=((m%16)+48);
/*------------------------------------------------------------------------------*/	
		lcd_cmd(0xc0);	tempread(); lcd_cmd(0x80);
/*---------------------------LIGHT INTENSITY STORD IN ARRAY----------------------*/
	adcip=readADC(1,0);   j=(100-((float)adcip/(float)4095)*100);
    info[8]=((j/10)%10)+48;   info[9]=(j%10)+48;    info[10]='%';  info[11]=' ';
/*--------------------------ADC VOLTAGE STORED IN INFO ARRAY---------------------*/
	adcip=readADC(0,0);   f=(((float)5/(float)4095)*adcip);  	j=f*10;
	info[12]=(j/10)+48;	 info[13]='.';	info[14]=(j%10)+48;	 info[15]='V';   info[16]='\0';
/*------------------------------------------------------------------------------*/
   	lcd_cmd(0x80);  lcd_string(info); /*lcd_cmd(0x87); lcd_data(' '); lcd_cmd(0x8b); lcd_data(' ');	 */
/**------------------------STORING info ON EXTERNAL ROM-------------------------*/		
			if(((((m/16)*10)+(m%16))%2)==0)
			{
					if(flg==0)
					{
						i=mloc[c];
						for(n=0;n<17;i++,n++)
						{ 
						i2c_write_frame(0xA0,i,info[n]);
						delay(10);
						}
						c++; flg=1;
					}
			}
				else flg=0;
/*-------------------------------------------------------------------------------------*/					
}
}
