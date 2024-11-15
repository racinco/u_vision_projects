
#include <delay8051.h>

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

void delay_ms(long delay){
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
