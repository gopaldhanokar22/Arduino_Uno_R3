#include <Arduino.h>
#include <LiquidCrystal.h>
// LCD Configuration
LiquidCrystal lcd(7, 8, 9, 10, 11, 12); // LCD Pins
// LM35 Temperature Sensor Pin
#define LM35_PIN A0
void setup() {
    lcd.begin(16, 2); // Initialize the LCD
    lcd.print("Temp Monitor");
    delay(2000);
    lcd.clear();
}
void loop() {
    int sensorValue = analogRead(LM35_PIN); // Read analog value from LM35
    float temperature = (sensorValue * 5.0 / 1023.0) * 100.0; // Convert to Celsius
    lcd.setCursor(0, 0);
    lcd.print("Temp: ");
    lcd.print(temperature);
    lcd.print(" C");
    delay(1000); // Refresh every 1 second
}
