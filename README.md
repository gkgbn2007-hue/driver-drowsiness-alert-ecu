# Driver Drowsiness Alert ECU

An educational embedded prototype intended to monitor eye-blink activity and provide an alert when a configured prolonged eye-closure condition is detected.

## Objectives
- Read an IR eye-blink sensor signal.
- Process the signal over time.
- Detect a configured prolonged eye-closure condition.
- Activate a buzzer and update an OLED when the alert condition is met.
- Test sensor reading, decision logic, and alert outputs separately.

## Hardware
Arduino UNO, ESP32, IR eye-blink sensor, buzzer, OLED display, connecting wires, and a suitable power source. The exact roles of the UNO and ESP32, wiring, and communication link must be confirmed from the actual build.

## Working principle
The IR sensor provides an eye-activity signal. The controller samples it, tracks the duration of the configured condition, and activates the buzzer and OLED alert when the condition is met. The reset/recovery behavior must be defined and tested in the firmware.

## Repository
- docs/system_design.md — functional design and details to verify.
- docs/testing_and_safety.md — bench test plan and safety notes.

## Validation status
Original firmware, exact wiring, thresholds, photographs, and measured performance were not supplied for this documentation update. No detection accuracy or response-time figure is claimed. Record repeatable test conditions and actual measurements before publishing performance results.

## Safety and limitations
This is not a certified driver-monitoring or vehicle-safety system. Never test while driving or rely on it as the sole driver-safety measure. It does not replace sleep, rest breaks, or responsible driving. IR sensing can be affected by placement, ambient light, movement, and individual differences.

## Author
Gurubaran G K — B.E. Electronics and Communication Engineering.
