#ifndef LCDLIBRARYRC_H_INCLUDED
#define LCDLIBRARYRC_H_INCLUDED

#include <reg51.h>
	
	// for minimum uses
	void init_4bit();
	void display(); // see datasheets for more modes
	void clear_display(); 
	void return_home(); 
	
	void lcd_cmd(unsigned char cmd_hex); 
	
	void write_oneLetter (unsigned char letter_hex); 
	void write_word(unsigned char *word);
	
	void shift (int mode);
	void backspace(); 
	void space(); 

#endifs