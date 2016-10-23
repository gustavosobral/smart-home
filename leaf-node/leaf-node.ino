#include <Thermistor.h>

#include <SPI.h>
#include <RF24_config.h>
#include <nRF24L01.h>
#include <RF24.h>

Thermistor temp(0);
int temperature;
int lightPin = 1;

void setup() {
  Serial.begin(9600);
}

void loop() {
  temperature = temp.getTemp();
  Serial.print("Sensor temperature: ");
  Serial.print(temperature);
  Serial.println("*C");

  Serial.print("Photoresistor: ");
  Serial.println(analogRead(lightPin));
  delay(1000);
}

