
#include <reg51.h>
#include <delay8051.h>
#include <lcdLibraryRC.h>



void main(){	
	int a ; 
		P2 = 0; 
		P1 = 0; 
	init_4bit();
	display(); 
	clear_display(); 
	return_home(); 
	write_word("HELLO");
}