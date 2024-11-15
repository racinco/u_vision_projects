#include<reg51.h>
// for 11.0592MHz Crystal
void delay(unsigned int count)
{
	unsigned int i;
	while(count)
	{
		i = 115;
		while(i > 0)
		   i--;
		count--;
	}
}

void main()
{
	unsigned char i;
	while(1)
	{
		for(i=0;i<=9;i++)
		{
		 P2 = 0x00;
		 delay(500);
		 P2 = 0xFF;
		 delay(500);
		}
		delay(1000);
		
		for(i=0;i<=9;i++)
		{
		 P2 = 0xAA;
		 delay(500);
		 P2 = 0x55;
		 delay(500);
		}
		delay(1000);
	}
}