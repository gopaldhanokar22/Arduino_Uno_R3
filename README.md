# Arduino_Uno_R3

__1. Title: Traffic Light System Using Arduino Uno__

*Objective*: Design a traffic light system using Red, Yellow, and Green LEDs that mimic real-world traffic signals.

*Functional Requirements*:
      - The Red LED should turn ON for 5 seconds (Stop Signal).
      - After that, the Yellow LED should turn ON for 2 seconds (Get Ready Signal).
      - The Green LED should turn ON for 5 seconds (Go Signal).
      - The cycle should repeat continuously.

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
  - After 5 seconds, it turns OFF.\

Step 2 (Get Ready Signal - Yellow LED ON)\
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

___________________________________________________________________________________________________________________________________________________________

__2. Title: Counter Control System Using Arduino Uno__

*Objective:* Write an Embedded C program that performs the following functions:

Switch 1 → Resets the counter to zero.
Switch 2 → Increments the counter by one.
Switch 3 → Decrements the counter by one.
Display the counter value on display.

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


____________________________________________________________________________________________________________________________________________________________
