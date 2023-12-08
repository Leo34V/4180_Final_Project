# 4180_Final_Project

## Introduction

This project is based on the previous idea of developing a piano using MPR121 touch keypad. Proposed improvements include adding a Adafruit bluetooth module for additional input, adding a more systematic power supply and utilizing RTOS to further eliminate the delay between the user input and the speaker output.<br />
[![Product Name Screen Shot][product-screenshot]](https://example.com)

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


## Connections

| Mbed  | Color LCD | Adafruit BLE | Speaker | MPR121 | TPA2005D1 | Voltage regulator | Relay |
| --- | --- | ---| --- | --- | ---| --- | --- |
| Vu | 5V  | Vin  | Content Cell  | Content Cell  | Content Cell  | Content Cell  | Content Cell  |
| gnd | gnd  | CTS  | Content Cell  | Content Cell  | Content Cell  | Content Cell  | Content Cell  |
| p28 |   | RXI  | Content Cell  | Content Cell  | Content Cell  | Content Cell  | Content Cell  |
| p27 |   | TXO  | Content Cell  | Content Cell  | Content Cell  | Content Cell  | Content Cell  |
| p22 |   |   | Content Cell  | Content Cell  | Content Cell  | Content Cell  | Content Cell  |
| p21 |   |   | Content Cell  | Content Cell  | Content Cell  | Content Cell  | Content Cell  |
| p14 | Tx  |   | Content Cell  | Content Cell  | Content Cell  | Content Cell  | Content Cell  |
| p13 | Rx  |   | Content Cell  | Content Cell  | Content Cell  | Content Cell  | Content Cell  |
| p11 | Reset  |   | Content Cell  | Content Cell  | Content Cell  | Content Cell  | Content Cell  |
| p10 |   |   | Content Cell  | Content Cell  | Content Cell  | Content Cell  | Content Cell  |
| p9 |   |   | Content Cell  | Content Cell  | Content Cell  | Content Cell  | Content Cell  |
| p5 |   |   | Content Cell  | Content Cell  | Content Cell  | Content Cell  | Content Cell  |


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



<!-- CONTRIBUTING -->
## Contributing

Contributions are what make the open source community such an amazing place to learn, inspire, and create. Any contributions you make are **greatly appreciated**.

If you have a suggestion that would make this better, please fork the repo and create a pull request. You can also simply open an issue with the tag "enhancement".
Don't forget to give the project a star! Thanks again!

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

<p align="right">(<a href="#readme-top">back to top</a>)</p>

