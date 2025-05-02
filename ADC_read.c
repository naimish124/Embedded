#include"header.h"
extern u_8 info[];
void ADC_read(void)
{
		u_16 adcip,j;
		float f;
	
		adcip=readADC(1,0); //read ADC channel-2  
		j=(100-((float)adcip/(float)4095)*100);//
    info[13]=((j/10)%10)+48;   
		info[14]=(j%10)+48;    
		info[15]='%';  
		info[16]=' ';
		delay(10);
	
		adcip=readADC(0,0);//read ADC channel-0   
		f=(((float)5/(float)4095)*adcip);  	
		j=f*10;
		info[17]=(j/10)+48;	 
		info[18]='.';	
		info[19]=(j%10)+48;	 
		info[20]='V'; 
		delay(10);  
}

