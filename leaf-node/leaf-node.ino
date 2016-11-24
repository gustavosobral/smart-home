#include <SPI.h>

#include <Thermistor.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(9,10);
const uint64_t pipe = 0xE13CBAF433LL;

Thermistor temp(0);
int lightPin = 1;
int gasPin = 5;

int temperature;
int luminosity;
int ppm;
int data[3];

void setup() {
  Serial.begin(9600);

  radio.begin();
  radio.openWritingPipe(pipe);
}

void loop() {
  temperature = temp.getTemp();
  luminosity = analogRead(lightPin);
  ppm = analogRead(gasPin);

  data[0] = luminosity;
  data[1] = temperature;
  data[2] = ppm;
  radio.write(data, sizeof(data));
}

