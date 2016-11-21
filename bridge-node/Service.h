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
    void init(byte * mac, IPAddress server, IPAddress ip);
    String postData(String data);
  private:
    EthernetClient _client;
    IPAddress _server;
    String handleResponse();
};

#endif