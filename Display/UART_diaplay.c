#include"header.h"
extern u_8 c;
extern u_8 mloc[];
void UART_display(void)
{
	u_8 i,m,cp=0;
	uart_txstring("\r\nLog ID \tTEMP \t Time \t Intensity \t Voltage \r\n");
		for(;cp<c;)
			{
				uart_tx(((cp+1)+48));
				uart_tx('\t');
				i=mloc[cp];
				for(m=0;m<17;i++,m++)
				{		if(m==7){uart_tx(' ');uart_tx('\t');	 }
						if(m==11){uart_tx(' ');uart_tx('\t');	 }
						if(m==14){uart_tx(' ');uart_tx('\t');	 }
						
						uart_tx(i2c_read_frame(0xA0,i));
						delay(10);
				}
						cp++;
						uart_txstring("\r\n");
				delay(50);
		  }	
}