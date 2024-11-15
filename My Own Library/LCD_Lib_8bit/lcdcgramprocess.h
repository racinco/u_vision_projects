#ifndef LCDGRAMPROCESS_H_INCLUDED
#define LCDGRAMPROCESS_H_INCLUDED

#include <reg51.h>
#include <delay8051.h>

	void init(); 
	void lcd_write(unsigned char hex); 
	//void cgram(); 
	void character(); 
	void character2();
	void return_home(); 
	void lcd_cmd(unsigned char hex); 

#endif