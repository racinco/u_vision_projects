// include the library for the registers of the 89c51 

#include <reg51.h>

void delay () 
{
	unsigned int i;	
	for ( i =0 ; i < 50000 ; i++);
}

void main () 
{
	
	while (1) {
		P2 = 0x00; // 0000 0000
		delay();
		P2 = 0x0f; // 0000 1111
		delay();
	}

}