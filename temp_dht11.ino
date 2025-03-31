#include <Arduino.h>
#include <DHT.h>
#include <LiquidCrystal.h>
// DHT11 Configuration
#define DHTPIN 2    // DHT11 data pin connected to Arduino pin 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
// LCD Configuration
LiquidCrystal lcd(7, 8, 9, 10, 11, 12); // LCD Pins
void setup() {
    lcd.begin(16, 2); // Initialize LCD
    dht.begin();     // Initialize DHT sensor
    lcd.print("DHT11 Monitor");
    delay(2000);
    lcd.clear();
}
void loop() {
    float temperature = dht.readTemperature(); // Read temperature in Celsius
    float humidity = dht.readHumidity();       // Read humidity percentage
    if (isnan(temperature) || isnan(humidity)) {
        lcd.setCursor(0, 0);
        lcd.print("Sensor Error");
    } else {
        lcd.setCursor(0, 0);
        lcd.print("Temp: ");
        lcd.print(temperature);
        lcd.print(" C");
        lcd.setCursor(0, 1);
        lcd.print("Humidity: ");
        lcd.print(humidity);
        lcd.print(" %");
    }
    delay(2000); // Refresh every 2 seconds
}
