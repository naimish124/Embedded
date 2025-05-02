#include<reg51.h>
#include"header.h"

sbit rs=P1^0;
sbit rw=P1^1;
sbit en=P1^2;
sfr lcd_port=0xA0;

void lcd_cmd(u_8 cmd)
{
	lcd_port=cmd;
	rs=0;
	rw=0;
	en=1;
	delay(3);
	en=0;
}
void lcd_data(u_8 dat)
{
	lcd_port=dat;
	rs=1;
	rw=0;
	en=1;
	delay(3);
	en=0;
}
void lcd_init()
{
	lcd_cmd(0x01);
	lcd_cmd(0x0c);
	lcd_cmd(0x02);
	lcd_cmd(0x38);	
}
void lcd_string(u_8 *p)
{
	while(*p)
		lcd_data(*p++);
}
