#include <SPI.h>

#include <Thermistor.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(9,10);
const uint64_t pipe = 0xE13CBAF433LL;

Thermistor temp(0);
int lightPin = 1;

int temperature;
int light;
int data[2];

void setup() {
  Serial.begin(9600);
  
  radio.begin();
  radio.openWritingPipe(pipe);
}

void loop() {
  temperature = temp.getTemp();
  light = analogRead(lightPin);

  data[0] = light;
  data[1] = temperature;
  radio.write(data, sizeof(data));
}

