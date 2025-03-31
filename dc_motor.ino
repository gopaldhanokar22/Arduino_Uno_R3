#include <Arduino.h>
// Motor Driver Pins (L298N)
#define MOTOR_IN1 5   // Motor Input 1 (Clockwise)
#define MOTOR_IN2 6   // Motor Input 2 (Anti-clockwise)
#define MOTOR_ENA 9   // Enable Pin for Motor Driver
// Switch Pins
#define SWITCH1 2 // Start Clockwise
#define SWITCH2 3 // Start Anti-clockwise
#define SWITCH3 4 // Stop Motor
void setup() {
    pinMode(MOTOR_ENA, OUTPUT);
    pinMode(MOTOR_IN1, OUTPUT);
    pinMode(MOTOR_IN2, OUTPUT);
    pinMode(SWITCH1, INPUT_PULLUP);
    pinMode(SWITCH2, INPUT_PULLUP);
    pinMode(SWITCH3, INPUT_PULLUP);
    digitalWrite(MOTOR_ENA, HIGH); // Enable the motor driver
    digitalWrite(MOTOR_IN1, LOW);
    digitalWrite(MOTOR_IN2, LOW);
}
void loop() {
    if (digitalRead(SWITCH1) == LOW) { // Clockwise Rotation
        digitalWrite(MOTOR_IN1, HIGH);
        digitalWrite(MOTOR_IN2, LOW);
    } else if (digitalRead(SWITCH2) == LOW) { // Anti-clockwise Rotation
        digitalWrite(MOTOR_IN1, LOW);
        digitalWrite(MOTOR_IN2, HIGH);
    } else if (digitalRead(SWITCH3) == LOW) { // Stop Motor
        digitalWrite(MOTOR_IN1, LOW);
        digitalWrite(MOTOR_IN2, LOW);
    }
}