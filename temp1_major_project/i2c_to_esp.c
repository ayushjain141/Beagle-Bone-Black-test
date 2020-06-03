#include <linux/i2c.h>
#include <linux/i2c-dev.h>
#include <linux/types.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define BUFFER_SIZE 10  
#define addr 0x38 	

int fd;
int adapter_num=1; 
char file_name[20];
char data[10];


void ambience_init() 
{

char init_buffer[2] = {0x40,0x80};
char mode_buffer[2] = {0x41,0x85};

fd = open("/dev/i2c-2",O_RDWR);
if(ioctl(fd,I2C_SLAVE,addr)<0)
	{
	 printf("\n==\nerror in the slave address write\n===\n");
	 exit(0);				
	}

write(fd, init_buffer, 2);
write(fd, mode_buffer, 2);
}

int sensor_read_ALS()
{

uint16_t data[2];
int i=0,res=0;

char als_addr_buffer[1]={0x46};
 
fd = open("/dev/i2c-2",O_RDWR);
if(ioctl(fd,I2C_SLAVE,addr)<0)
	{
	 printf("\n===\nerror in the slave address write\n===\n");
	 exit(0);				
	}

write(fd, als_addr_buffer, 1);

char read_buffer[2];
read(fd, read_buffer,2);

res=(int)( (read_buffer[1]<<8)|(read_buffer[0])) ;  

return res;

}


int main()
{ 

int sensor_value=0;
ambience_init();
	
	while(1)
	{
	sensor_value = sensor_read_ALS();
	printf("============\n");
	printf("%d\n",sensor_value);
	printf("============\n");
	usleep(100000);
	system("clear");
	}

 

return 1;
}



