#include <reg51.h>
#include <delay8051.h>
#include <lcdcgramprocess.h>


void main () {
	init();  
	lcd_write(33); 
	
	while (1); 
}