#include"header.h"
void exintr_en(void)
{
EA=EX0=1;IT0=0;
}
/*---------------------Interrupt 0 ISR---------------------*/
void isr_int0(void)	interrupt 0
{
  UART_display();
}
/*---------------------------------------------------------*/