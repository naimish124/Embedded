#include"header.h"
extern float Temperature;
extern s_16 th1;
void tempread()
{
		th1=i2c_device_read_temp();
		lcd_temp(th1/248);
		lcd_data('C');
}
