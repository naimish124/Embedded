#include"header.h"
 //bit f;
/*-----*****-------*****--------*****-----*/
void uart_init()
{
	SCON=0x50;
	TMOD=0x20;
	TH1=253; 
	TR1=1;
}

/*-----*****-------*****--------*****-----*/
void uart_tx(u_8 ch)
{
	SBUF=ch;
	while(TI==0);
	TI=0;
}
/*-----*****-------*****--------*****-----*/
void uart_txstring(u_8 *ptr)
{
	uart_tx('\r');
	uart_tx('\n');
	while(*ptr)
	{
		uart_tx(*++ptr);
	}

}
