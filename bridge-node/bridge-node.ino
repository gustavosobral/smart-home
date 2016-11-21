#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Ethernet.h>

#include "Service.h"

// Ethernet
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress server(192, 168, 25, 46);
IPAddress ip(192, 168, 25, 150); // Set the static IP address to use if the DHCP fails to assign

Service service;

// nRF24L01
RF24 radio(3, 4);
const uint64_t pipe = 0xE13CBAF433LL;
int data[1];

void setup() {
  Serial.begin(9600);
  SPI.begin();
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  Serial.print("Initializing...");
  
  radio.begin();
  radio.openReadingPipe(1, pipe);
  radio.startListening();
  service.init(mac, server, ip);

  Serial.println(" Ok!");
}

void loop() {
  if (radio.available()) {
    bool done = false;
    while (!done) {
      done = radio.read(data, sizeof(data));
      service.postData(String(data[0]));
    }
  }
}
