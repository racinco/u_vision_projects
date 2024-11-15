/*
NOTE: For the microncontroller to read the dta in the pins, first we need to place the internal latch HIGH. 
For example: 
	P1^0 = 1; place the internal latch high; 
	var = P1^0; read the value
*/
#include <reg51.h>
#include <delay8051.h>
#include <dht11LibRC.h>
#include <lcdLibraryRC.h>



 
void main () {
	delay(100);
	init_4bit();
	display();
	clear_display(); 	
	return_home(); 
	write_oneLetter('A'); 
	delay_ms(100);
	clear_display(); 
	while(1){	
			request(); 
			response();
			 //receive_data(); 
			dataSend();
			delay_ms(2000);
			clear_display(); 
	}
	
}