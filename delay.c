#include"header.h"
void delay(u_8 ms)
{
	unsigned int i;
	for(;ms>0;ms--)
	{
		for(i=0;i<1275;i++);
	}
}