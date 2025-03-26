# Arduino_Uno_R3

__1. Title: Traffic Light System Using Arduino Uno__

*Objective*: Design a traffic light system using Red, Yellow, and Green LEDs that mimic real-world traffic signals.

*Functional Requirements*:\
The Red LED should turn ON for 5 seconds (Stop Signal).\
After that, the Yellow LED should turn ON for 2 seconds (Get Ready Signal).\
The Green LED should turn ON for 5 seconds (Go Signal).\
The cycle should repeat continuously.

__Hardware Components Required:__
1. Microcontroller:
      - Arduino Uno R3 (1x)
2. LEDs:
      - Red LED (1x)
      - Yellow LED (1x)
      - Green LED (1x)
3. Resistors:
      - 220Ω Resistors (3x) (For current limiting with LEDs)  
4. Jumper Wires:
      - Male-to-male or Male-to-female jumper wires
5. Breadboard:
      - 1x Breadboard for circuit connections
6. Power Supply:
      - USB cable to power the Arduino

__Hardware Connection:__
![image](https://github.com/user-attachments/assets/111948aa-456f-4e99-a896-2fdda9fa0b79)


__Software Used:__
  1. Arduino IDE
  2. Proteus

__Software Simulation:__

![image](https://github.com/user-attachments/assets/b64a8855-795c-4aec-89c8-a311d32946ee)

__Hardware Simulation:__


__Working:__\
Traffic Light Sequence:\
Step 1 (Stop Signal - Red LED ON)
  - The Red LED turns ON.
  - This indicates that vehicles must stop.-
  - It remains ON for 5 seconds.
  - After 5 seconds, it turns OFF.

Step 2 (Get Ready Signal - Yellow LED ON)
  - The Yellow LED turns ON.
  - This acts as a transition phase, warning vehicles to get ready.
  - It remains ON for 2 seconds.
  - After 2 seconds, it turns OFF.

Step 3 (Go Signal - Green LED ON)
  - The Green LED turns ON.
  - This allows vehicles to move.
  - It remains ON for 5 seconds.
  - After 5 seconds, it turns OFF.

Repeat Cycle:
  - The sequence (Red → Yellow → Green) repeats continuously, just like real traffic lights at an intersection.\
   
__Project Code:__

```
#include <Arduino.h>
#define SWITCH1 2   // Reset Counter
#define SWITCH2 3   // Increment Counter
#define SWITCH3 4   // Decrement Counter
#define DISPLAY A0  // Display pin (Analog pin used for simplicity)
int counter = 0;  // Counter variable
void setup() {
    pinMode(SWITCH1, INPUT_PULLUP);
    pinMode(SWITCH2, INPUT_PULLUP);
    pinMode(SWITCH3, INPUT_PULLUP);
    pinMode(DISPLAY, OUTPUT);
    Serial.begin(9600);  // For serial monitor display
}
void loop() {
    if (digitalRead(SWITCH1) == LOW) {
        counter = 0;    // Reset counter
        Serial.println("Counter Reset to Zero");
        delay(200);     // Debounce delay
    }
    if (digitalRead(SWITCH2) == LOW) {
        counter++;     // Increment counter
        Serial.print("Counter Incremented: ");
        Serial.println(counter);
        delay(200);     // Debounce delay
    }
    if (digitalRead(SWITCH3) == LOW) {
        counter--;     // Decrement counter
        Serial.print("Counter Decremented: ");
        Serial.println(counter);
        delay(200);     // Debounce delay
    }
    displayCounter(counter);  // Display updated counter value
}
// Function to simulate counter display (using Serial Monitor here)
void displayCounter(int value) {
    Serial.print("Current Counter Value: ");
    Serial.println(value);
    delay(500);  // Refresh delay for stability
}
```

______________________________________________________________________________________________________________________

__2. Title: Counter Control System Using Arduino Uno__

*Objective:* Write an Embedded C program that performs the following functions:

Switch 1 → Resets the counter to zero.\
Switch 2 → Increments the counter by one.\
Switch 3 → Decrements the counter by one.\
Display the counter value on display.

__1. Hardware Components Required:__
 - Arduino Uno – The main microcontroller board.
 - LCD Display (16x2, I2C) – Used to display the counter value.
 - I2C Module (PCF8574) – For interfacing the LCD with Arduino.
 - Push Buttons (3) – For Reset, Increment, and Decrement functions.
 - Resistors (10kΩ) (Optional) – For external pull-up (if not using internal pull-ups).
 - Jumper Wires – For circuit connections.
 - Breadboard – For assembling the circuit.
 - 5V Power Supply – Can be provided via Arduino USB or external adapter.

__2. Hardware Connections:__
![image](https://github.com/user-attachments/assets/f2fd20a8-935c-4a41-8a6f-81054c095f7e)

 - The switches are configured using internal pull-up resistors in the code.
 - When a button is pressed, it connects the respective pin to GND (LOW state), triggering the respective action.

__3. Software Used:__
 - Arduino IDE 
 - Proteus 

__4. Working of the Project:__
System Initialization:
 - The LCD is initialized using the I2C module.
 - Push buttons are set as input with internal pull-up resistors enabled.

Button Press Actions:
 - Switch 1 (D2) - Reset Counter:
  - When pressed, the counter resets to 0.
 - Switch 2 (D3) - Increment Counter:
  - When pressed, the counter increases by 1.
 - Switch 3 (D4) - Decrement Counter:
  - When pressed, the counter decreases by 1.

Display Update:
- The updated counter value is displayed on the 16x2 LCD.
- A small delay (200ms) is added for debouncing to avoid accidental multiple counts.

Continuous Execution:
- The process runs in an infinite loop (loop() function), ensuring that the system responds to button presses continuously.

__software Simulation:__
![image](https://github.com/user-attachments/assets/a1eb1086-7314-437d-a6dd-f4db9b74e634)

__Hardware Simulation:__

__Project code:__
```
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
// Initialize LCD with I2C address 0x27 (check your module's address)
LiquidCrystal_I2C lcd(0x20, 16, 2);
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
```

_________________________________________________________________________________________________________________________________
