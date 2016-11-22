#include <SPI.h>
#include <Ethernet.h>

#include <nRF24L01.h>
#include <RF24.h>
#include <ArduinoJson.h>

#include "Service.h"
#define UUID "5d4144ea-93c6-480b-90dc-e3f474df4ce0"

// Ethernet
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress server(192, 168, 25, 46);
IPAddress ip(192, 168, 25, 150); // Set the static IP address to use if the DHCP fails to assign

// nRF24L01
RF24 radio(3, 4);
const uint64_t pipe = 0xE13CBAF433LL;
int data[2];

// JSON
StaticJsonBuffer<200> jsonBuffer;
JsonObject& root = jsonBuffer.createObject();
JsonArray& luminosity = root.createNestedArray("luminosity");
JsonArray& temperature = root.createNestedArray("temperature");

Service service;
int i = 0;
String request;

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
  root.set("uuid", UUID);

  Serial.println(" Ok!");
}

void loop() {

  if (radio.available()) {
    bool done = false;

    while (!done) {
      done = radio.read(data, sizeof(data));
      luminosity.add(data[0]);
      temperature.add(data[1]);

      if(i == 9) {
        root.printTo(request);
        service.postData(request);

        i = 0;
        jsonBuffer = StaticJsonBuffer<200>();
      }
      i++;
    }
  }
}
