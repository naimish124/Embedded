#include"header.h"
u_8 mloc[]={0x00,0x15,0x2A,0x3F,0x54,0x69,0x7E,0x93,0xA8,0xbD,0xD2,0xE7};
u_8 aloc[]={0xA0,0xA2};//0-12AM//0-12PM
bit flg=0;
u_8 c=0;
extern u_8 info[];
extern u_8 m;
void EEPROM_write()
{
		u_8 n,i,v; ;//n-array count//i-memory location//v-add location
	  m=i2c_read_frame(0xD0,0x1);//read min
		delay(10);
				if(((((m/16)*10)+(m%16))%2)==0)
			{
					if(flg==0)
					{
						if(c>=12)
						{ i=mloc[(c-12)]; v=aloc[1];}
						else
						{	i=mloc[c];			v=aloc[0];}
	
						for(n=0;n<21;i++,n++)
						{ 
						i2c_write_frame(v,i,info[n]);
						delay(10);
						}
						c++; flg=1;
					}
			}
				else flg=0;
			if(c==24)
				c=0;
}