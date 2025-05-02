#include"header.h"
float Temperature;
s_16 th1;
extern u_8 info[];
void TEMP_read()
{
	
		u_16 i,sum=0,c=0,temp=0;
		th1=i2c_device_read_temp();
		th1=th1/248;
		temp=th1;
	if(temp==0)
	{	
		info[8]='0';		info[9]='0';		info[10]='0';		info[11]='C';			
	}
	
	if(temp<0)
	{
		info[8]='-';
		i=-temp;
	}
	else
	{	info[8]='+';  i=temp; }
	
	for(c=0;i;i=i/10)
	{
		 sum=sum*10+i%10;
		 c++;
	}
	i=sum;
	info[9]=((i%10)+48);
	i=i/10;
	info[10]=((i%10)+48);
	info[11]='C';
	info[12]=' ';
	}