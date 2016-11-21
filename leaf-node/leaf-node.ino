#include <Thermistor.h>

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(9,10);
const uint64_t pipe = 0xE13CBAF433LL;

Thermistor temp(0);
int lightPin = 1;

int temperature;
int light;
int data[1];

void setup() {
  Serial.begin(9600);
  
  radio.begin();
  radio.openWritingPipe(pipe);
}

void loop() {
  temperature = temp.getTemp();
  light = analogRead(lightPin);

  data[0] = light;
  radio.write(data, sizeof(data));
}

