# smart-home
Final project for the Wireless Sensor Network class

## NRF24L01

![NRF24L01](doc/images/nrf24l01_pins.png)

### leaf-node

| Pin |   Name   |  Arduino  |
|:---:|:--------:|:---------:|
|  1  |   GND    |    GND    |
|  2  |   VCC    |    3.3V   |
|  3  |   CE     |     9     |
|  4  |   CS     |    10     |
|  5  |   SCK    |    13     |
|  6  |   MOSI   |    11     |
|  7  |   MISO   |    12     |
|  8  |   IRQ    |   Unused  |

### bridge-node

| Pin |   Name   |  Arduino  |
|:---:|:--------:|:---------:|
|  1  |   GND    |    GND    |
|  2  |   VCC    |    3.3V   |
|  3  |   CE     |     9     |
|  4  |   CS     |    10     |
|  5  |   SCK    |    52     |
|  6  |   MOSI   |    51     |
|  7  |   MISO   |    50     |
|  8  |   IRQ    |   Unused  |
