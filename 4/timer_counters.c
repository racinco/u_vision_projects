#include <reg51.h>

sbit led = P2^0 ;

void init_registers(){
		TMOD = 0x01; // 0000 0001 ; 16bit timer mode 
}

void delay_timer(long delay){
		int a; 
		for ( a = 0; a < delay; a++){
		// read the timer overflow flag // if it counts up then exit while loop 
		TH0 = 0xFC; // for 1 ms second 0x00; // start from 0 
		TL0 = 0x18; // for 1 ms second //0x00; // start from 0 
		TR0 = 1 ; // start the timer 
		while (TF0==0); 
		TR0 = 0 ; // stop the timer the timer 
		TF0 = 0; // reset the overflow flag 
		}
}

void main (){
	
	init_registers(); // initilize the registers
	P2 = 0x00; 
	
	while(1){
		led = 1 ;
		delay_timer(10);
		led = 0; 
		delay_timer(10); 
	}
	
}

