#include"header.h"
sbit CLK=P1^4;
sbit DOUT=P1^5;
sbit DIN=P1^6;
sbit CS=P1^7;
u_16 readADC(bit b1,bit b2)
{
	u_16 temp=0;
	s_8 i;
	CS=0;//enable adc
	CLK=1;
	CLK=0; DIN=1; CLK=1;//start condition
	CLK=0; DIN=1; CLK=1;//single/diff setting
	CLK=0; DIN=0; CLK=1;//mode selection
	CLK=0; DIN=b1; CLK=1;//ch sel
	CLK=0; DIN=b2; CLK=1;//ch sel
	CLK=0; CLK=1;//dont care
	CLK=0, CLK=1;//dont care null bit
	for(i=11;i>=0;i--)
	{
		CLK=0;
		if(DOUT==1)
					temp|=(1<<i);
		CLK=1;
	}
	delay(10);
	CS=1;
	return temp;
}