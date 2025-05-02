#include<reg51.h>
typedef  unsigned int u_16;
typedef signed int s_16;
typedef unsigned char u_8;
typedef signed char s_8;

extern void RTC_read(void);
extern void TEMP_read(void);
extern void ADC_read(void);
extern void EEPROM_write(void);
extern void LCD_display(void);
extern void UART_display(void);

extern void lcd_init();
extern void lcd_data(u_8 );
extern void lcd_cmd(u_8 );
extern void lcd_string(u_8*);

extern void uart_init();
extern void uart_tx(u_8);
extern void uart_txstring(u_8*);

extern void exintr_en();
extern void isr_int0(void);

extern void delay(u_8 );

extern void i2c_start();
extern void i2c_stop();
extern void i2c_write(u_8);
extern u_8 i2c_read(void);
extern void i2c_ack();
extern void i2c_nack(void);
extern void i2c_write_frame(u_8 ,u_8 ,u_8 );
extern u_8 i2c_read_frame(u_8 ,u_8 );

extern u_16 readADC(bit ,bit );

void initDs1621(void);
s_16 i2c_device_read_temp(void);
void i2c_cmd_write(u_8 sa,u_8 cmd);
void i2c_Page_Write(u_8 SlaveId,u_8 SlaveMemoryId,u_8 Count,u_8 *info);
void i2c_Page_Read(u_8 SlaveId,u_8 SlaveMemoryId,u_8 Count,u_8 *ubuf); 	//argument slave addr/memory addr
void temp_init(void);

