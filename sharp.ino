#include <Arduino.h>
#include <LiquidCrystal.h>
// Sharp Distance Sensor and Buzzer Pins
#define SENSOR_PIN A0 // Analog pin connected to the Sharp sensor output
// LCD Configuration
LiquidCrystal lcd(7, 8, 9, 10, 11, 12); // LCD Pins
void setup() {
    pinMode(SENSOR_PIN, INPUT);
    lcd.begin(16, 2); // Initialize LCD
    lcd.print("Sharp Sensor");
    delay(2000);
    lcd.clear();
}
void loop() {
    int sensorValue = analogRead(SENSOR_PIN); // Read analog value
    float voltage = sensorValue * (5.0 / 1023.0); // Convert to voltage
    // Distance estimation formula (varies by sensor model)
    float distance = 27.86 * pow(voltage, -1.15); // Sample equation for GP2Y0A21YK sensor
    lcd.setCursor(0, 0);
    lcd.print("Dist: ");
    lcd.print(distance);
    lcd.print(" cm ");
    lcd.setCursor(0, 1);
    lcd.print("Volt: ");
    lcd.print(voltage);
    lcd.print(" V");
    delay(500); // Refresh every 500ms
}
