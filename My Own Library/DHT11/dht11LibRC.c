
#include <dht11LibRC.h>
#include <lcdLibraryRC.h>
#include <stdio.h>

sbit dataBus = P2^0; 
// starts the communication process

sbit LED = P1^0;
void request () {
/*
	1. hosts pulls low for min 18ms
	2. hosts pulls up for 20-40 us 
	3. Sensor pulls low for 80 us 
	4. Sensor pulls up for 80 us 
	*/
	dataBus = 0 ; 
	delay_ms(20); 
	dataBus = 1; 

}
void response (){
	while (dataBus == 1); 
	while (dataBus == 0); 
	while (dataBus == 1);
}

void dataSend ()
{
/*
	1. DHT 11 sends data by frist pulling the databus LOW for 50 us 
	2. Then pulls up HIGH 
	3. The lenght of the HIGH Signal determines if it is "1" or "0"
	4. 1: 70us | 0: 26-28us 
	5. THEN pulls low again for next transmission 
*/ 
	signed char bits [40] ; 
	unsigned int bytes [5]; 
	int counter , val , power ; 
	unsigned char converted_hum [5], converted_temp[5] ; 
	counter = val = power = 0 ; 
	
	bytes[0] = bytes[1] = bytes[2] = bytes[3] = bytes[4]  = 0 ;
	
	for (counter = 0 ; counter < 40 ; counter++){
		while (dataBus == 0); // waits the transmit siganl from the sensor 
		delay_us(); 
		if (dataBus == 1) {
			bits [counter] = 1 ; 
		}else {
			bits [counter] = 0; 
		}
	}
	
	// convert the bits to different parts of the dta
	for ( counter = 0 ; counter < 40 ; counter++  ){
		 bytes [counter/8] <<= 1; 
     bytes[counter/8] = bytes[counter/8] | bits[counter];
	}
	
	// convert hexadecimal to string
	
	if ( (bytes[0] + bytes[1] + bytes[2] + bytes[3]) == bytes[4] ){
		sprintf(converted_hum,"%d.%d", bytes[0], bytes[1]);
		write_word(converted_hum); 
		sprintf(converted_temp,"%d.%d", bytes[2],bytes[3]); 
		write_word(converted_temp); 
	}else {
		write_word("error");
	}
	
}

void receive_data()
{	 
	int i,c=0;
	for(i=0;i<8;i++)
	{
		while(dataBus==0);
	//	delay_us(30);
		
			if(dataBus==1){
				c=(c<<1)|(0x01);}
			else{
				c=c<<1;}
			
		while(dataBus==1);
	}
	
	write_oneLetter(c); 
}






