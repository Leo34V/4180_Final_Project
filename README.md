# 4180_Final_Project

## Introduction

This project is based on the previous idea of developing a piano using MPR121 touch keypad. Proposed improvements include adding a Adafruit bluetooth module for additional input, adding a more systematic power supply and utilizing RTOS to further eliminate the delay between the user input and the speaker output.<br />
![alt text](https://github.com/Leo34V/4180_Final_Project/blob/main/IMG_0257.JPG?raw=true)
## Components usage

Mbed NXP LPC1768 <br />
MPR121 Capacitive Touch Sensor Breakout Boar <br />
TTL Level RS232 Color Graphics LCD display <br />
Speaker (Sparkfun 64 ohm, 0.5 W) <br />
Adafruit Bluefruit LE UART Friend - Bluetooth Low Energy (BLE) <br />
Li-ion 7.4V battery pack <br />
Relay <br />
Voltage regulator <br />
Class D high-efficiency audio amp TPA2005D1 <br />

## Description
### Functionality
The MPR121 touch keypad controls the pitch of the speaker/piano. Hardware interrupt ensures fast and stable response. RTOS was utilized with three threads, controlling the BLE, LCD and speaker behaviors respectively. Bluetooth module has the ability of tuning the volume and pitch, and has 4 preset speaker outputs. But due to the speed of the bluetooth communication, developers suggest to use it mainly as a volume tuning device. LCD display indicates information including the key pressed on the touch keypad and the volume/pitch level. 
### Power
1 relay terminal with input signal connecting to the mbed Vout (high) was instrumented to control the power input from the 7.4V Li-ion battery. The power trace goes into a 5V voltage regulator, supplying power for BLE, LCD, Speaker.

## Connections

| Mbed  | Color LCD | Adafruit BLE | Speaker | MPR121 | TPA2005D1 | Voltage regulator | Relay |
| --- | --- | ---| --- | --- | ---| --- | --- |
| Vout |   |   |   |  Content Cell  | Content Cell  | Content Cell  |
| gnd | gnd  | CTS  |   |  | Content Cell  | Content Cell  | Content Cell  |
| p28 |   | RXI  |   |   | Content Cell  | Content Cell  | Content Cell  |
| p27 |   | TXO  |   |   | Content Cell  | Content Cell  | Content Cell  |
| p22 |   |   |  |   | Content Cell  | Content Cell  | Content Cell  |
| p21 |   |   |  | IRQ | Content Cell  | Content Cell  | Content Cell  |
| p14 | Tx  |   |   |   | Content Cell  | Content Cell  | Content Cell  |
| p13 | Rx  |   |   |  | Content Cell  | Content Cell  | Content Cell  |
| p11 | Reset  |   |   |   | Content Cell  | Content Cell  | Content Cell  |
| p10 |   |   |  | SCL(Pull-Up 4.7k)  | Content Cell  | Content Cell  | Content Cell  |
| p9 |   |   |   | SDA(Pull-Up 4.7k)  | Content Cell  | Content Cell  | Content Cell  |
| p5 |   |   |   |   | Content Cell  | Content Cell  | Content Cell  |


<!-- ROADMAP -->
## Roadmap

- [x] Add Changelog
- [x] Add back to top links
- [ ] Add Additional Templates w/ Examples
- [ ] Add "components" document to easily copy & paste sections of the readme
- [ ] Multi-language Support
    - [ ] Chinese
    - [ ] Spanish

See the [open issues](https://github.com/othneildrew/Best-README-Template/issues) for a full list of proposed features (and known issues).

<p align="right">(<a href="#readme-top">back to top</a>)</p>



## Demo

[![Watch the video](https://i.stack.imgur.com/Vp2cE.png)](https://youtu.be/k_Nj4KE3edo)
