/*
 * Driver Drowsiness Alert ECU - starter firmware
 * Target: Arduino UNO + digital-output IR eye-blink sensor + buzzer.
 * Optional display: I2C SSD1306 128x64 OLED at address 0x3C.
 *
 * Assumed wiring:
 * IR sensor OUT -> D2; buzzer signal -> D8; OLED SDA -> A4, SCL -> A5.
 * Verify whether your sensor output is active LOW or active HIGH.
 *
 * Libraries: Adafruit GFX, Adafruit SSD1306.
 * This is an educational prototype, not a certified driver-safety device.
 * Test only on a bench. Never test while driving or rely on it to decide
 * whether it is safe to drive.
 */

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define IR_SENSOR_PIN 2
#define BUZZER_PIN 8
#define OLED_WIDTH 128
#define OLED_HEIGHT 64
#define OLED_RESET -1
#define OLED_ADDRESS 0x3C

// Set to LOW if the sensor output goes LOW when the configured
// detected state is present. Verify the actual module output on a bench.
const uint8_t EYE_CLOSED_LEVEL = HIGH;
const unsigned long ALERT_AFTER_MS = 2000;
const unsigned long SENSOR_SAMPLE_MS = 20;

Adafruit_SSD1306 display(OLED_WIDTH, OLED_HEIGHT, &Wire, OLED_RESET);

unsigned long closedSinceMs = 0;
unsigned long lastSampleMs = 0;
bool alertActive = false;
bool displayAvailable = false;

void updateDisplay(const char *status) {
  if (!displayAvailable) return;

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println(F("Drowsiness Alert ECU"));
  display.setCursor(0, 24);
  display.print(F("Status: "));
  display.println(status);
  display.setCursor(0, 48);
  display.println(F("Bench prototype only"));
  display.display();
}

void setup() {
  pinMode(IR_SENSOR_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW);
  Serial.begin(9600);

  displayAvailable = display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDRESS);
  if (!displayAvailable) {
    Serial.println(F("OLED not found; continuing without display."));
  } else {
    updateDisplay("Starting");
  }

  Serial.println(F("Drowsiness ECU ready. Verify sensor polarity."));
}

void loop() {
  const unsigned long now = millis();
  if (now - lastSampleMs < SENSOR_SAMPLE_MS) return;
  lastSampleMs = now;

  const bool detectedState = (digitalRead(IR_SENSOR_PIN) == EYE_CLOSED_LEVEL);

  if (detectedState) {
    if (closedSinceMs == 0) closedSinceMs = now;
    alertActive = (now - closedSinceMs >= ALERT_AFTER_MS);
  } else {
    closedSinceMs = 0;
    alertActive = false;
  }

  digitalWrite(BUZZER_PIN, alertActive ? HIGH : LOW);

  static bool previousAlert = false;
  if (alertActive != previousAlert) {
    Serial.println(alertActive ? F("ALERT: prolonged sensor state")
                               : F("INFO: sensor state recovered"));
    previousAlert = alertActive;
    updateDisplay(alertActive ? "ALERT" : "Normal");
  }
}
