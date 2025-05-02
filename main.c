#include"header.h"
void main()
{
	lcd_init(); //lcd initialization 
	uart_init();//uart initialization 
	exintr_en();//external interrupt enable EINT0
	temp_init();//temprature sensor initialization
	delay(250);
/*----------------for clock setting----------------*/
// 	   i2c_write_frame(0xD0,0x2,0x65); //hr
//     i2c_write_frame(0xD0,0x1,0x02); //min
//     i2c_write_frame(0xD0,0x0,0x00); //sec
/*-------------------------------------------------*/
	while(1)
	{
		RTC_read();
		TEMP_read();
		ADC_read();
		EEPROM_write();
		LCD_display();
	}
}