#include <reg51.h>
#include <nrf_lib.h>

void main(){
	unsigned char a, stat;
		P2 = 0x00; 
	nRF_config();

	while(1){
		a= 1;
    stat = TX_PL(&a);	
	}
	
}
