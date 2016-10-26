#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(9,10);
const uint64_t pipe = 0xE13CBAF433LL;

int data[1];

void setup() {
  Serial.begin(57600);
  
  radio.begin();
  radio.openReadingPipe(1, pipe);
  radio.startListening();
}

void loop() {
  if (radio.available()) {
    bool done = false;
    while (!done) {
      done = radio.read(data, sizeof(data));
      Serial.print("Recieved: ");
      Serial.println(data[0]);
    }
  }
}
