// Title: Ultrasonic Sensor (HC-SR04) Interfacing with MCU
//
// Objective:
// Write an Embedded C program to interface an Ultrasonic Sensor (HC-SR04) with the MCU that performs the following tasks:
// - Measure the distance of an object in centimeters (cm) using the ultrasonic sensor.
// - Display the measured distance on an LCD display or Serial Monitor.
// - If the detected distance is less than 10 cm, activate a buzzer or LED alert for warning.

#include <Arduino.h>
#include <LiquidCrystal.h>
// Ultrasonic Sensor Pins
#define TRIG_PIN 2
#define ECHO_PIN 3
#define BUZZER_PIN 4
// LCD Configuration
LiquidCrystal lcd(7, 8, 9, 10, 11, 12); // LCD Pins
void setup() {
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
    pinMode(BUZZER_PIN, OUTPUT);
    lcd.begin(16, 2); // Initialize LCD
    lcd.print("Ultrasonic Sensor");
    delay(2000);
    lcd.clear();
}
float getDistance() {
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);
    long duration = pulseIn(ECHO_PIN, HIGH);
    float distance = (duration * 0.034) / 2; // Distance in cm
    return distance;
}
void loop() {
    float distance = getDistance();
    lcd.setCursor(0, 0);
    lcd.print("Dist: ");
    lcd.print(distance);
    lcd.print(" cm ");
    if (distance < 10) {
        digitalWrite(BUZZER_PIN, HIGH);
        lcd.setCursor(0, 1);
        lcd.print("ALERT: Object! ");
    } else {
        digitalWrite(BUZZER_PIN, LOW);
        lcd.setCursor(0, 1);
        lcd.print("                "); // Clear alert line
    }
    delay(500); // Refresh every 500ms
}
