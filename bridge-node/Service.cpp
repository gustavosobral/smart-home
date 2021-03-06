/*
  Service.cpp - Library for consuming Web Services API's.
  Created by Gustavo Sobral, Febuary 26, 2016.
*/

#include "Arduino.h"
#include "Service.h"

Service::Service(){};

void Service::init(byte * mac, char* server, IPAddress ip) {
  if (Ethernet.begin(mac) == 0) {
    Ethernet.begin(mac, ip);
  }
  _server = server;
}

String Service::postData(String body) {
  // if you get a connection, report back via serial:
  if (_client.connect(_server, 8000)) {
    // Make a HTTP request:
    _client.println("POST /api/v1/data HTTP/1.1");
    _client.println("Host: " + String(_server));
    _client.println("User-Agent: arduino-ethernet");
    _client.println("Accept: application/json");
    _client.println("Content-Type: application/json");
    _client.println("Cache-Control: no-cache");
    _client.println("Connection: close");
    _client.print("Content-Length: ");
    _client.println(body.length());
    _client.println();
    _client.println(body);
    _client.println();
  } else {
    // if you didn't get a connection to the server:
    Serial.println("connection failed");
    return "";
  }
  return handleResponse();
}

String Service::handleResponse() {
  boolean stringComplete = false;
  String inputString = "";
  
  while(true) {
    if (_client.available()) {
      char c = _client.read();
      inputString += c;

      // Skips the HTTP Header
      if(inputString == "\r\n") {
        inputString = "";
        stringComplete = true;
      }
      // Clear after each new line
      if(!stringComplete && c == '\n') {
        inputString = "";
      }
    }

      // if the server's disconnected, stop the client:
    if (!_client.connected()) {
      _client.stop();
      break;
    }
  }

  return inputString;
}
