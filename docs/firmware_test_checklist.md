# Firmware Test Checklist — Driver Drowsiness Alert ECU

This checklist is for an electronics bench demonstration only. Do not test while driving or rely on this prototype to judge whether a person is safe to drive.

## Build and startup

- [ ] Confirm the actual controller is Arduino UNO for this starter sketch.
- [ ] Install required OLED libraries if the display is fitted.
- [ ] Firmware compiles without errors.
- [ ] Upload completes.
- [ ] Serial Monitor opens at 9600 baud.
- [ ] Startup message is observed and saved.

## Sensor and output checks

- [ ] Confirm the sensor module supply voltage.
- [ ] Verify the digital output polarity on a bench.
- [ ] Set `EYE_CLOSED_LEVEL` to match the measured logic.
- [ ] Confirm normal sensor state does not activate the buzzer.
- [ ] Confirm the configured prolonged input state activates the buzzer as coded.
- [ ] Confirm return to normal state deactivates the buzzer.
- [ ] Confirm optional OLED status updates if fitted.

## Evidence record

| Field | Record |
|---|---|
| Test date | |
| Controller and sensor module | |
| Sensor active logic level | |
| Configured demonstration interval | |
| Buzzer module type | |
| OLED fitted/address | |
| Observed behavior | |
| Firmware commit | |
| Evidence file names | |
| Issues and notes | |

The demonstration timer is not a validated drowsiness threshold. Do not claim real-world detection accuracy or automotive safety performance from this prototype.
