# Prototype Test Cases — Driver Drowsiness Alert ECU

> Status: planned bench verification cases. This educational prototype is not a certified driver-monitoring or safety device.

| ID | Test | Procedure | Expected observation | Result |
|---|---|---|---|---|
| DDA-01 | Startup | Power the board from an approved USB supply | Startup message/status appears | Not run |
| DDA-02 | Normal sensor state | Present the sensor's normal unobstructed state | No prolonged-closure alert is triggered | Not run |
| DDA-03 | Sensor state change | Change the sensor input using a safe bench test method | Input state is detected consistently | Not run |
| DDA-04 | Alert timing | Use a simulated sensor input in a controlled bench test | Alert occurs only after configured duration | Not run |
| DDA-05 | Buzzer output | Observe buzzer during a simulated alert | Audible indication matches configured alert logic | Not run |
| DDA-06 | Sensor fault | Test disconnected or invalid sensor input | Fault/invalid state is handled safely and reported | Not run |

## Safety and limitations
- Test on a bench; do not use while driving or rely on this prototype to decide whether someone is safe to drive.
- Sensor readings can be affected by placement, lighting, glasses, and movement.
- This prototype is not a medical device, certified automotive ECU, or replacement for rest and safe driving practices.

## Evidence to add after testing
Record sensor model, board, pin mapping, threshold and timing configuration, test date, observed serial output, and photographs. Change a result to **Pass** or **Fail** only after the test is actually performed.
