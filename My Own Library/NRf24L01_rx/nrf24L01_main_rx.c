#include <reg51.h>
#include <nrf_lib.h>

void main (){

	unsigned char *rec;
	P2=0x00;
  nRF_config();
  while(1)
  {
    rec=RX_PL();
		if (rec == 1){
			P2 = 0xFF; 
		}
	}
	
}