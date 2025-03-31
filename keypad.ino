#include <LiquidCrystal.h>
#include <Keypad.h>
// LCD Pins (RS, EN, D4, D5, D6, D7)
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
// Keypad Configuration
const byte ROWS = 4; // Four rows
const byte COLS = 4; // Four columns
char keys[ROWS][COLS] = {
    {'1', '2', '3', '+'},
    {'4', '5', '6', '-'},
    {'7', '8', '9', '*'},
    {'C', '0', '=', '/'}
};
byte rowPins[ROWS] = {A0, A1, A2, A3};
byte colPins[COLS] = {A4, A5, 2, 3};
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
// Variables to store data
char key;
float num1 = 0, num2 = 0;
char operatorSymbol;
bool isOperatorSelected = false;
void setup() {
    lcd.begin(16, 2); // Initialize LCD
    lcd.print("Calculator Ready");
    delay(2000);
    lcd.clear();
}
void loop() {
    key = keypad.getKey();

    if (key) {
        if (key >= '0' && key <= '9') {
            lcd.print(key);
            if (!isOperatorSelected) {
                num1 = (num1 * 10) + (key - '0');
            } else {
                num2 = (num2 * 10) + (key - '0');
            }
        } else if (key == '+' || key == '-' || key == '*' || key == '/') {
            lcd.print(key);
            operatorSymbol = key;
            isOperatorSelected = true;
        } else if (key == '=') {
            lcd.setCursor(0, 1);
            lcd.print("=");
            float result = calculateResult(num1, num2, operatorSymbol);
            lcd.print(result);
        } else if (key == 'C') {
            lcd.clear();
            lcd.print("Calculator Ready");
            delay(1000);
            lcd.clear();
            num1 = 0; num2 = 0;
            isOperatorSelected = false;
        }
    }
}
// Calculation Logic
float calculateResult(float n1, float n2, char op) {
    switch (op) {
        case '+': return n1 + n2;
        case '-': return n1 - n2;
        case '*': return n1 * n2;
        case '/': return (n2 != 0) ? (n1 / n2) : 0; // Avoid division by zero
        default: return 0;
    }
}