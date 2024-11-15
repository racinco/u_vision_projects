// include the library for the registers of the 89c51 

#include <reg51.h>

void delay () 
{
	unsigned int i;	
	for ( i =0 ; i < 50000 ; i++);
}

void main () 
{
	P0 = 0x00;
	P2 = 0x00; // 0000 0000
	while (1) {
		
		// enable the pins needed.
		P0 = 0x35;	
		P2 = 0x35; // 11001100
		
		delay();
		// reverse the direction counter clockwise
		P0 = 0x00;
		P2 = 0x00;
		
		delay ();
		P0 = 0x56;
		P2 = 0x56; 
		
		delay();
		/*
		P0 = 0x88;
		P2 = 0x88; // 0000 0000
		delay();
		*/
	}
}
