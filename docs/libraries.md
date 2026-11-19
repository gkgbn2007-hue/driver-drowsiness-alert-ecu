# Software and Library Requirements

## Hardware target

- Arduino UNO or compatible board
- Digital-output IR eye-blink sensor module
- Active buzzer module (assumed by simple HIGH/LOW control)
- Optional SSD1306 I2C OLED, 128 × 64

## Arduino IDE

1. Install Arduino IDE.
2. Select the correct UNO board and serial port.
3. Open `firmware/driver_drowsiness_alert.ino`.
4. Install the following libraries through Library Manager if using the OLED:
   - Adafruit GFX Library
   - Adafruit SSD1306
5. Compile and upload.

The sketch uses the built-in `Wire` library for I2C. If the OLED is not fitted, the code continues with serial and buzzer functions, but the display library dependencies are still required by the current source.

## Serial Monitor

Open Serial Monitor at **9600 baud**. The firmware prints a startup message and reports when its simple prolonged-sensor-state alert changes.

## Configuration

Verify sensor output polarity and set `EYE_CLOSED_LEVEL` accordingly. The 2-second threshold is a demonstration parameter only; it is not a clinically or automotive validated drowsiness threshold.
