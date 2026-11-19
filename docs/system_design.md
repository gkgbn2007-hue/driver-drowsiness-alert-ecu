# System Design — Driver Drowsiness Alert ECU

## Intended functional flow
IR eye-blink sensor → controller input → time-based decision logic → buzzer and OLED alert.

The project description includes Arduino UNO and ESP32. Their exact responsibilities and any communication link must be confirmed from the original circuit or rebuilt hardware before documenting pin assignments.

## Functional blocks
1. Sensor input: read the IR sensor and verify active-high/active-low behavior.
2. Signal interpretation: convert sensor readings into a documented eye-activity state.
3. Decision logic: track the duration of the configured condition using a timing method that does not unnecessarily block other tasks.
4. Alert output: activate the buzzer and update the OLED.
5. Recovery: define and test how the system clears the alert.

## Details to confirm from the actual build
- IR sensor model, output type, and operating voltage.
- Roles of Arduino UNO and ESP32.
- Verified pin map and wiring diagram.
- Communication interface, if present.
- OLED controller, resolution, and interface.
- Eye-closure threshold and selection method.
- Alert timing, reset behavior, and power arrangement.

No pin assignments or threshold values are assumed here.
