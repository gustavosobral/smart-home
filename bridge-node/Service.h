/*
  Service.h - Library for consuming Web Services API's.
  Created by Gustavo Sobral, Febuary 26, 2016.
*/

#ifndef Service_h
#define Service_h

#include "Arduino.h"

#include <SPI.h>
#include <Ethernet.h>

class Service
{
  public:
    Service();
    void init(byte * mac, char* server, IPAddress ip);
    String postData(String data);
  private:
    EthernetClient _client;
    char* _server;
    String handleResponse();
};

#endif
