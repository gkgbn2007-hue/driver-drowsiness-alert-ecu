# Pin Connections — Driver Drowsiness Alert ECU

> These are assumed connections for the starter sketch. Check the exact sensor module's output polarity and electrical levels before wiring.

## Arduino UNO example

| Module | Module pin | Arduino UNO pin | Notes |
|---|---|---|---|
| IR eye sensor | OUT | D2 | Digital output; polarity must be verified |
| IR eye sensor | VCC | Per module specification | Confirm 5 V compatibility |
| IR eye sensor | GND | GND | Common ground |
| Buzzer module | Signal/+ | D8 | Confirm whether it is active or passive |
| Buzzer module | GND/- | GND | Common ground |
| SSD1306 OLED (optional) | SDA | A4 | I2C data |
| SSD1306 OLED (optional) | SCL | A5 | I2C clock |
| SSD1306 OLED (optional) | VCC | Per module specification | Check module voltage |
| SSD1306 OLED (optional) | GND | GND | Common ground |

## Firmware settings

The sketch currently assumes:

- Sensor output is HIGH when eye closure is detected.
- A continuous detected state lasting 2 seconds activates the buzzer.
- OLED address is 0x3C.

If the sensor uses the opposite polarity, change `EYE_CLOSED_LEVEL` in the sketch after confirming the output with a safe bench test.

## Safety limitation

This is an educational demonstration only. Sensor placement, ambient light, eyewear, individual variation and motion can affect readings. It is not a medical device or certified driver-monitoring system. Never use it while driving or rely on it to determine driver alertness.
