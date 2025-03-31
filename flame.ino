#include <Arduino.h>
#include <LiquidCrystal.h>
// Fire Sensor and Buzzer Pins
#define FIRE_SENSOR_PIN A0 // Analog pin connected to the fire sensor output
#define BUZZER_PIN 3       // Buzzer pin for alert
// LCD Configuration
LiquidCrystal lcd(7, 8, 9, 10, 11, 12); // LCD Pins
void setup() {
    pinMode(FIRE_SENSOR_PIN, INPUT);
    pinMode(BUZZER_PIN, OUTPUT);
    lcd.begin(16, 2); // Initialize LCD
    lcd.print("Fire Sensor");
    delay(2000);
    lcd.clear();
}
void loop() {
    int sensorValue = analogRead(FIRE_SENSOR_PIN); // Read analog value

    // Fire detection logic (higher voltage typically indicates fire presence)
    if (sensorValue > 500) { // Threshold value may vary with sensor
        lcd.setCursor(0, 0);
        lcd.print("Fire Detected!");
        digitalWrite(BUZZER_PIN, HIGH); // Activate buzzer for alert
    } else {
        lcd.setCursor(0, 0);
        lcd.print("No Fire       ");
        digitalWrite(BUZZER_PIN, LOW); // Deactivate buzzer
    }
    delay(500); // Refresh every 500ms
}
