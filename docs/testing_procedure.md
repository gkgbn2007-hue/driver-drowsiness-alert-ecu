# Bench Testing Procedure

> This project is an educational prototype, not a certified safety system. Test the electronics on a bench only. Never test it while driving or use it to decide whether it is safe to drive.

## 1. Pre-checks

- Verify sensor supply voltage and output voltage compatibility with the UNO.
- Confirm buzzer module type and current requirements.
- Confirm OLED voltage and I2C address if fitted.
- Verify sensor output polarity before relying on the firmware setting.

## 2. Startup check

- Compile and upload the sketch.
- Open Serial Monitor at 9600 baud.
- Confirm the startup message appears.
- Confirm the optional OLED initializes if fitted.

## 3. Sensor input check

- Observe the sensor's digital output using a safe, controlled bench setup.
- Confirm which logic level represents the sensor's detected state.
- Set `EYE_CLOSED_LEVEL` to match the verified sensor output.
- Do not interpret this simple sensor output as a reliable measurement of a person's alertness.

## 4. Alert output check

- Use a controlled test signal or carefully operate the sensor on the bench.
- Confirm the buzzer output activates after the configured continuous detection interval.
- Confirm the buzzer turns off when the sensor returns to its normal state.
- Confirm the serial alert messages match the output behavior.

## 5. Test record

| Test | Expected observation | Actual result |
|---|---|---|
| Firmware startup | Ready message appears | To be recorded |
| Sensor polarity | Verified and documented | To be recorded |
| Normal input | Buzzer remains off | To be recorded |
| Prolonged detected input | Buzzer activates after configured interval | To be recorded |
| Input returns to normal | Buzzer deactivates | To be recorded |
| Optional OLED | Status text updates | To be recorded |

Attach actual photographs, serial logs and observed results. Do not mark tests as passed until performed on the real prototype.
