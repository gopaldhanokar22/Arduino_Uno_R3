#include <Arduino.h>
// Define LED pins
const int redLED = 11;    // Red LED connected to pin 9
const int yellowLED = 12; // Yellow LED connected to pin 10
const int greenLED = 13;  // Green LED connected to pin 11
void setup() {
    // Set LED pins as output
    pinMode(redLED, OUTPUT);
    pinMode(yellowLED, OUTPUT);
    pinMode(greenLED, OUTPUT);
}
void loop() {
    // Red LED ON (Stop Signal)
    digitalWrite(redLED, HIGH);
    digitalWrite(yellowLED, LOW);
    digitalWrite(greenLED, LOW);
    delay(5000); // 5 seconds delay
    // Yellow LED ON (Get Ready Signal)
    digitalWrite(redLED, LOW);
    digitalWrite(yellowLED, HIGH);
    digitalWrite(greenLED, LOW);
    delay(2000); // 2 seconds delay
    // Green LED ON (Go Signal)
    digitalWrite(redLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(greenLED, HIGH);
    delay(5000); // 5 seconds delay
}
