#include <LiquidCrystal.h> // Library for LCD interfacing
// LCD pin connections
#define RS 7
#define EN 8
#define D4 9
#define D5 10
#define D6 11
#define D7 12
// Initialize the LCD (16x2) with defined pins
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);
#define RESET_BUTTON 2   // Pin for Reset Button
int counter = 0;         // Counter Variable
void setup() {
    lcd.begin(16, 2);      // Initialize LCD (16 columns, 2 rows)
    lcd.setCursor(0, 0);   // Cursor at Row 1, Column 0
    lcd.print("Hello World!"); // Display initial message

    pinMode(RESET_BUTTON, INPUT_PULLUP); // Internal pull-up for the reset button
}
void loop() {
    // Check if the reset button is pressed
    if (digitalRead(RESET_BUTTON) == LOW) {
        counter = 0;      // Reset counter to zero
        lcd.clear();      // Clear LCD screen
        lcd.setCursor(0, 0);
        lcd.print("Hello World!"); // Display initial message again
        delay(200);       // Debouncing delay
    }
    // Display Counter on Second Row
    lcd.setCursor(0, 1);  // Cursor at Row 2, Column 0
    lcd.print("Counter: ");
    lcd.print(counter);   // Display Counter Value
    // To handle digit overwriting, add spaces after digits
    lcd.print("   ");     // Clears additional digits when resetting the counter
    counter++;            // Increment Counter
    delay(1000);          // 1-second delay
}
