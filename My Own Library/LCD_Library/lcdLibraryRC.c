#include<reg51.h>
#include<delay8051.h>

/* This code is for 4bit operation of the LCD

	*lcd_cmd function is used to call on differnt instructions according to the datasheets
	* 
	ADD Functions: 
	1. Read busy flag function
	2. Add the custom character generation function
*/


sbit RS = P1^0;
sbit RW = P1^1; 
sbit E = P1^2; 

sbit D4 = P2^4;
sbit D5 = P2^5;
sbit D6 = P2^6;
sbit D7 = P2^7;

void init_4bit(){
	 RS = 0; RW =0;   E = 0; D6 = 0; D7 = 0;
                delay_ms(1);
                D5 = 1;
                D4 = 1;
                E = 1;
                delay_ms(1);
                E = 0;
                delay_ms(1);

                D5 = 1;
                D4 = 1;
                E = 1;
                delay_ms(1);
                E = 0;
                delay_ms(1);

                D5 = 1;
                D4 = 1;
                E = 1;
                delay_ms(1);
                E = 0;
                delay_ms(1);

                D5 = 1;
                D4 = 0;
                E = 1;
                delay_ms(1);
                E = 0;
                delay_ms(1);
}

void lcd_cmd (unsigned char cmd_hex){
	RS = 0; 
	RW = 0; 
	delay_ms(1);
	// First 4 bits
	if(cmd_hex & 0x80) D7 = 1 ; else D7 = 0; 
	if(cmd_hex & 0x40) D6 = 1 ; else D6 = 0; 
	if(cmd_hex & 0x20) D5 = 1 ; else D5 = 0; 
	if(cmd_hex & 0x10) D4 = 1 ; else D4 = 0; 
	
	E = 1; 
	delay_ms(1);
	E = 0 ; 
	delay_ms(1);
	
	// Last 4 bits
	if(cmd_hex & 0x08) D7 = 1 ; else D7 = 0; 
	if(cmd_hex & 0x04) D6 = 1 ; else D6 = 0; 
	if(cmd_hex & 0x02) D5 = 1 ; else D5 = 0; 
	if(cmd_hex & 0x01) D4 = 1 ; else D4 = 0; 	
	
	E = 1; 
	delay_ms(1);
	E = 0 ; 
	delay_ms(1);
}

void display(){
	lcd_cmd(0x0C); 
}

void write_letter(){
	RS = 1 ; 
	RW = 0 ; 
	
	delay_ms(1); 
	
	// instruction set
	D7 = 0; 
	D6 = 1; 
	D5 = 0; 
	D4 = 0; 
	
	E = 1; 
	delay_ms(1); 
	E = 0 ; 
	delay_ms(1);
	
		// instruction set
	D7 = 1; 
	D6 = 0; 
	D5 = 0; 
	D4 = 0; 
	
	E = 1; 
	delay_ms(1); 
	E = 0 ; 
	delay_ms(1);
}

void write_oneLetter(unsigned char letter_hex){
	RS = 1; 
	RW = 0; 
	delay_ms(1);
	// First 4 bits
	if(letter_hex & 0x80) D7 = 1 ; else D7 = 0; 
	if(letter_hex & 0x40) D6 = 1 ; else D6 = 0; 
	if(letter_hex& 0x20) D5 = 1 ; else D5 = 0; 
	if(letter_hex & 0x10) D4 = 1 ; else D4 = 0; 
	
	E = 1; 
	delay_ms(1);
	E = 0 ; 
	delay_ms(1);
	
	// Last 4 bits
	if(letter_hex & 0x08) D7 = 1 ; else D7 = 0; 
	if(letter_hex & 0x04) D6 = 1 ; else D6 = 0; 
	if(letter_hex & 0x02) D5 = 1 ; else D5 = 0; 
	if(letter_hex& 0x01) D4 = 1 ; else D4 = 0; 	
	
	E = 1; 
	delay_ms(1);
	E = 0 ; 
	delay_ms(1);
}


void write_word(unsigned char *word){
	while(*word != 0){
		write_oneLetter(*word);
		word++ ; 
	}
	
}

void shift (int mode ) {
	switch (mode){	
		case 0: // shift all display right 
			lcd_cmd (0x1C); 
		break; 
		case 1: // shift all display left 
			lcd_cmd(0x18);
		case 2: // shift cursor right 
			lcd_cmd (0x14); 
		case 3: // shift cursor left
			lcd_cmd (0x10); 
	}
}

void backspace(){
	shift(3); 
	write_oneLetter(0x08); 
	shift(3); 
}
void space(){
	write_oneLetter(0x20); 
}

void clear_display() { lcd_cmd(0x01); }
void return_home(){ lcd_cmd(0x02);}














