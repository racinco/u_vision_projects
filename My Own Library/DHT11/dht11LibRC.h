#ifndef DHT11LIBRC_H_INCLUDED
#define DHT11LIBRC_H_INCLUDED

#include <reg51.h>
#include <delay8051.h>

void request (); 
void response(); 
void dataSend(); 
void receive_data();

#endif

