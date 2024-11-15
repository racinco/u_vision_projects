
/* This code sued the 8bit function of the LCD 

	1. lcd_cmd lets us write the instuction according to the datasheets
	2. lcd_cmd write lets us write chacracters stored in ROM 
	3. character lets us create our own sutom character from scratch.  
*/

# include <lcdcgramprocess.h>





sbit RS = P1^0;
sbit RW = P1^1;
sbit E = P1^2;



void lcd_data (unsigned char dat){
	P2 = dat;

	E = 1;
	delay_ms(1);
	E =0 ;
	delay_ms(1);

}

void lcd_cmd (unsigned char hex){
	RS =0;
	RW =0;
	lcd_data(hex);
}

void lcd_write (unsigned char hex){
	RS =1 ;
	RW =0;
	lcd_data(hex);
	delay_ms(1);
}


void send (unsigned char *string) {
	while(*string){
		lcd_write(*string);
		*string++;
	}
}



void init(){
	lcd_cmd(0x38); //LCD 4-bit mode and 2 lines.
	lcd_cmd(0x0E); // display
}

void return_home(){
	lcd_cmd(0x02);
}
void character(){
	unsigned char person [] = { 0x1C , 0x1C , 0x0A, 0x0F, 0x08, 0x14, 0x12, 0x00};
	lcd_cmd(0x40); // set the cgram adress
	send (person); // send the 7bit or 8bit data. Take note tat 8 bit is empty for the cursor
	lcd_cmd(0xC1); // indicate the DDRAM Address to write the data
	lcd_write(0);  // indicate what data to be printed.
	delay_ms(50);
}
void character2(){
	unsigned char person [] = { 0x1C , 0x1C , 0x0A, 0x0F, 0x08, 0x14, 0x12, 0x00};
	lcd_cmd(0x48); // set the cgram adress
	send (person);
	lcd_cmd(0xC0);
	lcd_write(0);
	delay_ms(50);
}

