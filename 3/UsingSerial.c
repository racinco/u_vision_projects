#include <reg51.h>
#include <myownlib.h>

sbit led = P2^0;
void uart_init (){
	TMOD =  0x20; // 0010 0000
	
	// 0101 0000 // ( Mode: 8bit UART, Variable by timer 1) 
	//REN = 1 ( enable 8051 to receive data ) 
	SCON = 0x50; 
	
	TH1 = 0xFD; //Baud rate : (255 + 1) - 0xFD(253) = 3 ticks before restart
	TL1 = 0xFD; // Same as TH1
	
	TR1 = 1 ; // start the timer
}

void uart_write(unsigned char str){
	// writes a single character in SBUF
	
	SBUF = str; // send string character in SBUF
	while(TI == 0); // wait confirmation of sending 
	
	TI = 0 ; // manually reset the Transmission Flag
	
}

void uart_write_string (unsigned char *str){
	while(*str){
		uart_write(*str); 
		str++;
	}
}



unsigned char uart_read(){

		while(RI ==0); 		// check if RI is active 	
		RI = 0 ; // reset the RI for the next transmission
		return SBUF;
}


unsigned char read;


void main() {
 
	
	P2 = 0x00;
	uart_init(); 
	uart_write_string("Hello Serial Port"); // take note that a single character 'a', meanwhile "a" is a doble character with 'a' & 0 (null character)
	
	while(1){
		int a ;
		//read = uart_read (); // reads the input from the virtual terminal 
		// write again the character but add 1 
		
		led = 1;
		delay_ms(500); 

		a= 254;
		uart_write(a);
		led = 0 ;
		delay_ms(500); 
	}
	

}






