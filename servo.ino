#include <Arduino.h>
#include <Servo.h>
#include <LiquidCrystal.h>
// Servo Motor and LCD Configuration
Servo servoMotor;
LiquidCrystal lcd(7, 8, 9, 10, 11, 12); // LCD Pins
// Button Pins
#define BUTTON1 2  // Move to 0 degrees
#define BUTTON2 3  // Move to 90 degrees
#define BUTTON3 4  // Move to 180 degrees
void setup() {
    servoMotor.attach(6); // Servo signal pin
    lcd.begin(16, 2);
    pinMode(BUTTON1, INPUT_PULLUP);
    pinMode(BUTTON2, INPUT_PULLUP);
    pinMode(BUTTON3, INPUT_PULLUP);
    lcd.print("Servo Control");
    delay(2000);
    lcd.clear();
}
void loop() {
    if (digitalRead(BUTTON1) == LOW) {
        servoMotor.write(0); // Move servo to 0°
        lcd.clear();
        lcd.print("Angle: 0 Deg");
    } else if (digitalRead(BUTTON2) == LOW) {
        servoMotor.write(90); // Move servo to 90°
        lcd.clear();
        lcd.print("Angle: 90 Deg");
    } else if (digitalRead(BUTTON3) == LOW) {
        servoMotor.write(180); // Move servo to 180°
        lcd.clear();
        lcd.print("Angle: 180 Deg");
    }
}
