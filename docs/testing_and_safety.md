# Testing and Safety — Driver Drowsiness Alert ECU

## Bench-only test plan
Do not test this prototype while driving. Use a stationary setup and controlled sensor tests.

| Test | Procedure | Record |
|---|---|---|
| Sensor baseline | Observe sensor output under normal test positioning and lighting. | Raw output and conditions |
| Sensor state change | Change the sensor target in a controlled bench test. | State transition and stability |
| Alert timing | Apply a controlled input pattern representing the configured condition. | Threshold and measured activation time |
| Buzzer | Verify activation and reset behavior. | Pass/fail |
| OLED | Verify normal and alert status. | Pass/fail and observations |
| Recovery | Restore normal input condition. | Reset behavior |
| Disturbance | Repeat under different safe lighting/position conditions. | False triggers or missed transitions |

## Safety and limitations
- Never use the prototype as a reason to continue driving when tired.
- Do not test on a moving vehicle or public road.
- Sensor readings may vary with ambient light, position, movement, and hardware tolerances.
- False alerts and missed alerts are possible.
- This is an educational prototype, not a certified safety product.

## Evidence checklist
- [ ] Actual prototype photograph
- [ ] Verified circuit diagram and pin map
- [ ] Firmware source and library versions
- [ ] Test conditions and raw observations
- [ ] Alert timing measurements
- [ ] Known limitations
