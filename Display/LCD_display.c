#include"header.h"
extern u_8 mloc[];
extern u_8 info[];
void LCD_display(void)
{
	u_8 i;
	lcd_cmd(0x01);
	for(i=0;i<21;i++)
	{
		if(i==8){lcd_string("TMP ");}
		if(i==12){lcd_cmd(0xc0); lcd_string("INT");}
		if(i==16){lcd_string(" VOL");}
		lcd_data(info[i]);
	}
}