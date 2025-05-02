#include"header.h"
void i2c_Device_Write(u_8 SlaveId,u_8 Commands,u_8 info) //argument slave addr/ memory addr/ data
{ 
	i2c_start();
	i2c_write(SlaveId); 					//write slave addr with write option
	i2c_ack();
	i2c_write(Commands); 				//write memory aadr
	i2c_ack();
	i2c_write(info); 						//write data
	i2c_ack();
	i2c_stop();
}

u_8 i2c_Device_Read(u_8 SlaveId,u_8 Commands) 	//argument slave addr/memory addr
{
	u_8 temp=0;
	i2c_start();
	i2c_write(SlaveId); 		//dummy  write slave aadr +write option
	i2c_ack();
	i2c_write(Commands); 	//dummy write memory addr
	i2c_ack();
	
	i2c_start(); 				//restart condition
	i2c_write(SlaveId|1); 		//read slave addr with read option 
	i2c_ack();
	temp=i2c_read();
	i2c_nack(); 				//optional
	i2c_stop();
	return temp;
}

s_16 i2c_device_read_temp(void)
{
	s_16 th;
	u_8 temp[2],slop,count;
	u_16 tempr;
	i2c_cmd_write(0x90,0xEE);
	delay(50);
	i2c_cmd_write(0x90,0x22);
	delay(5);

	i2c_Page_Read(0x90,0xAA,2,temp);
	delay(10);
	slop=i2c_Device_Read(0x90,0xA9);
	delay(5);
	count=i2c_Device_Read(0x90,0xA8);
	delay(5);
	tempr=temp[0];
	tempr=(tempr<<8)|temp[1];
	th=(tempr-0.25)+((slop-count)/slop);

	return th;
}

void i2c_cmd_write(u_8 sa,u_8 cmd)
{
	i2c_start();
	i2c_write(sa);
	i2c_ack();
	i2c_write(cmd);
	i2c_ack();
	i2c_stop();
}

void i2c_Page_Write(u_8 SlaveId,u_8 SlaveMemoryId,u_8 Count,u_8 *info)
{
	 u_8 i;
	 i2c_start();
	 i2c_write(SlaveId);
	 i2c_ack();
	 i2c_write(SlaveMemoryId);
	 i2c_ack();
	 for(i=0;i<Count;i++)
	 {
	 	i2c_write(info[i]);
		delay(2);
		i2c_ack();
	 }
	 i2c_stop();
}
 /*--I2C PAGE READ FRAME--*/
void i2c_Page_Read(u_8 SlaveId,u_8 SlaveMemoryId,u_8 Count,u_8 *ubuf) 	//argument slave addr/memory addr
{
	u_8 i;
	i2c_start();
	i2c_write(SlaveId); 		//dummy  write slave aadr +write option
	i2c_ack();
	i2c_write(SlaveMemoryId); 	//dummy write memory addr
	i2c_ack();
	i2c_stop();
	
	for(i=0;i<Count;i++)
	{
		i2c_start(); 				//restart condition
 		i2c_write(SlaveId|1); 		//read slave addr with read option
		i2c_ack();
	 	ubuf[i]=i2c_read();
		i2c_nack();
		i2c_stop();		
	} 			
}
 
void temp_init()
{
	u_8 te[3];
	i2c_Device_Write(0x90,0xAC,0x02);
	delay(2);
	te[0]=0x28;te[1]=0x0;
	i2c_Page_Write(0x90,0xA1,2,te);
	delay(2);
	te[0]=0x0A;te[1]=0x0;
	i2c_Page_Write(0x90,0xA2,2,te);
	delay(2);
}


