#include "header.h"
extern u_8 mloc[];
extern u_8 aloc[];
extern u_8 c;
void UART_display(void)
{
	extern u_8 c;

	u_8 m,cp=0,i,v;
	uart_txstring("\r\nLog ID \tTime \t Temp \t Intensity \t Voltage \r\n");
		while(cp<c)
			{
				uart_tx((((cp+1)/10)+48));		uart_tx((((cp+1)%10)+48));
				uart_tx('\t');
				if(cp>=12)
						{ i=mloc[(cp-12)]; v=aloc[1];}
				else
						{	i=mloc[cp];			v=aloc[0];}
	
				
				for(m=0;m<21;i++,m++)
				{		if(m==7){uart_tx(' ');/*uart_tx('\t');*/	 }
						if(m==13){uart_tx(' ');uart_tx('\t');uart_tx(' ');	 }
						if(m==17){uart_tx(' ');uart_tx('\t');uart_tx('\t');uart_tx(' ');	 }
						
						uart_tx(i2c_read_frame(v,i));
						delay(1);
				}
						cp++;
						uart_txstring("\r\n");
				delay(5);
		  }	
}