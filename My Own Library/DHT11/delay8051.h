#ifndef DELAY8051_H_INCLUDED
#define DELAY8051_H_INCLUDED

#include <reg51.h>

void delay(unsigned int count); // delays the reg51 by some number, though this counting is not accurate
void delay_ms(long delay); //delays for 1 ms
void delay_us ();

void timer_delay_30us();
#endif
