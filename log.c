			#include<reg51.h>
            #include"header.h" 
		
			u8 k=0x00,j=0x20,m=0x36,data1,data2,data3;		
				 void data_log()
					{
						uart_tx_string("\r\n              ........WEATHER REPORT............           \r\n");
						delay_ms(100);		 
		                  while(k<0x1E)
			                 {				   
					                data1=i2c_device_read(0xA0,k);
							            delay_ms(30);
					                
	    			             uart_tx(data1/16+48);
							           uart_tx(data1%16+48);  
												 delay_ms(3);
												 k++;
												     if(k%3==0)
														 {
														    uart_tx_string("\t\t");
														   	data2=i2c_device_read(0xA0,j);
															delay_ms(30); 
															uart_tx(data2/10+48);
							                                uart_tx(data2%10+48);
															delay_ms(60); 
															j++;

															uart_tx('.');
															data2=i2c_device_read(0xA0,j);
															delay_ms(30);   
															uart_tx(data2/10+48);
							                                uart_tx(data2%10+48);
															delay_ms(30); 
															j++;

															uart_tx_string("\t\t");
														   	data3=i2c_device_read(0xA0,m);
															delay_ms(30); 
															uart_tx(data3/10+48);
							                                uart_tx(data3%10+48);
															uart_tx('%');
															delay_ms(10); 
															m++;
								                            uart_tx_string("\r\n");
															continue;
														 }
														 
							           uart_tx(':');
									   delay_ms(100);	
				                 }
									 k=0x00;j=0x20;m=0x36;
		           }	  									