#include <Wire.h>
#include <LiquidCrystal_I2C.h>
// Initialize LCD with I2C address 0x27 (check your module's address)
LiquidCrystal_I2C lcd(0x27, 16, 2);
#define SWITCH1 2  // Reset Counter
#define SWITCH2 3  // Increment Counter
#define SWITCH3 4  // Decrement Counter
int counter = 0;
void setup() {
    lcd.init();               // Initialize the LCD
    lcd.backlight();          // Turn on LCD backlight
    lcd.setCursor(0, 0);
    lcd.print("Counter: 0");
    pinMode(SWITCH1, INPUT_PULLUP); // Configure switches with internal pull-up
    pinMode(SWITCH2, INPUT_PULLUP);
    pinMode(SWITCH3, INPUT_PULLUP);
}
void loop() {
    if (digitalRead(SWITCH1) == LOW) {
        counter = 0; // Reset counter
        delay(200);  // Debouncing delay
    }
    if (digitalRead(SWITCH2) == LOW) {
        counter++;   // Increment counter
        delay(200);  // Debouncing delay
    }
    if (digitalRead(SWITCH3) == LOW) {
        counter--;   // Decrement counter
        delay(200);  // Debouncing delay
    }
    lcd.setCursor(0, 0);
    lcd.print("Counter:    ");  // Clear old data
    lcd.setCursor(9, 0);       // Align counter value
    lcd.print(counter);
}
