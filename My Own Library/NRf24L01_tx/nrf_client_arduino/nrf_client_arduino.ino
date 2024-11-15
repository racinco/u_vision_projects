#include <SPI.h>
#include <RH_NRF24.h>

RH_NRF24 nrf24;

String movement; 
void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  while (!Serial){} ;                          // Wait for serial port to connect. Needed for Leonardo only
  if (!nrf24.init())
    Serial.println("init failed");           // Defaults after init are 2.402 GHz(channel 2), 2Mbps, 0dBm                              
  if (!nrf24.setChannel(110))
    Serial.println("setChannel failed");
  if (!nrf24.setRF(RH_NRF24::DataRate2Mbps, RH_NRF24::TransmitPower0dBm))
    Serial.println("setRF failed");    
  if (nrf24.init())
    Serial.println("init success"); 
    
}


void loop() {

// get the data
  if (nrf24.available())
  {
    uint8_t buf[RH_NRF24_MAX_MESSAGE_LEN];   // Should be a message for us now
    uint8_t len = sizeof(buf);
    if(nrf24.recv(buf, &len))
    {
      Serial.print("got request: ");
      movement = (char*)buf ;
      Serial.println(movement.toInt());
    }
    else
    {
      Serial.println("recv failed");
    }
  }
// put your main code here, to run repeatedl




}
