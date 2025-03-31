#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Initialize LCD with I2C address 0x27
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int irPin1 = 2; // IR sensor 1 (Entrance Detector)
const int irPin2 = 3; // IR sensor 2 (Exit Detector)

int in_count = 0;
int out_count = 0;
int current_count = 0;

const unsigned long timeout = 50; // Object detection Timeout

void setup() {
  Serial.begin(9600); // Debugging purpose
  
  // Initialize LCD
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("IN: 0   OUT: 0");
  lcd.setCursor(0, 1);
  lcd.print("Current: 0");

  // Configure IR sensor pins
  pinMode(irPin1, INPUT_PULLUP);
  pinMode(irPin2, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(irPin1) == LOW) {
    unsigned long startTime = millis();
    while ((millis() - startTime) < timeout) {
      if (digitalRead(irPin2) == LOW) {
        in_count++;
        updateDisplay();
        break;
      }
    }
    while (!digitalRead(irPin1) || !digitalRead(irPin2)); // Wait for sensors to reset
  }

  if (digitalRead(irPin2) == LOW) {
    unsigned long startTime = millis();
    while ((millis() - startTime) < timeout) {
      if (digitalRead(irPin1) == LOW) {
        if (out_count < in_count) {
          out_count++;
          updateDisplay();
          break;
        }
      }
    }
    while (!digitalRead(irPin1) || !digitalRead(irPin2)); // Wait for sensors to reset
  }
}

void updateDisplay() {
  lcd.setCursor(4, 0);
  lcd.print("   ");
  lcd.setCursor(4, 0);
  lcd.print(in_count);

  lcd.setCursor(13, 0);
  lcd.print("   ");
  lcd.setCursor(13, 0);
  lcd.print(out_count);

  current_count = in_count - out_count;
  lcd.setCursor(9, 1);
  lcd.print("   ");
  lcd.setCursor(9, 1);
  lcd.print(current_count);

  Serial.print("IN: ");
  Serial.print(in_count);
  Serial.print(" OUT: ");
  Serial.print(out_count);
  Serial.print(" Current: ");
  Serial.println(current_count);
  
  delay(100); // Small delay for LCD update
}
