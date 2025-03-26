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
__3. Title: Seven Segment Display - Counting 0 to 9 Using Arduino Uno__

*Objective:* Write an Embedded C  program to interface a 7-segment display with MCU that:

Displays digits from 0 to 9 sequentially.\
Each digit should be displayed with a 1-second delay.\
The sequence should continuously repeat.

__1. Hardware Components Required:__
 - Microcontroller (MCU) - Arduino Uno (or any other MCU).
 - 7-Segment Display (Common Cathode) – To display digits.
 - Resistors (220Ω - 1kΩ) – To limit current for segment LEDs.
 - Jumper Wires – For making connections.
 - Breadboard – For circuit assembly.
 - 5V Power Supply – Provided via Arduino or an external source.

2. Hardware Connections:\
![image](https://github.com/user-attachments/assets/99bd85bd-b39d-4ef2-8548-85d91f114c4d)

 - The seven segments (a-g) are connected to digital pins (D2-D8) on the Arduino Uno.
 - The Common Cathode (CC) pin is connected to GND.
 - Resistors (220Ω - 1kΩ) are connected between each segment and the Arduino to prevent excessive current.

__3. Software Used:__
 - Arduino IDE
 - Proteus 

__4. Working of the Project:__\
System Initialization:
 - The seven segment pins (D2-D8) are configured as OUTPUT.
 - The common cathode is connected to GND.

Displaying Digits from 0 to 9:
 - The system continuously displays numbers from 0 to 9.
 - Each number is displayed using a predefined bit pattern for the 7-segment display.
 - The function displayDigit(int num) sets the segment states based on the digit to be displayed.

Timing Control:
 - Each digit stays on for 1 second (1000ms) before switching to the next digit.
 - The cycle repeats indefinitely (loop() function).

Continuous Execution:
- The numbers cycle through automatically in a loop, ensuring the display keeps running.

__Software Simulation:__

![image](https://github.com/user-attachments/assets/eefc9e44-f439-45d5-b584-63b669121182)

__Harware Simulation:__

__Project Code:__
```
// Pin mapping for 7-segment display segments (Common Cathode Type)
#define a 2  // Segment 'a' connected to Digital Pin 2
#define b 3  // Segment 'b' connected to Digital Pin 3
#define c 4  // Segment 'c' connected to Digital Pin 4
#define d 5  // Segment 'd' connected to Digital Pin 5
#define e 6  // Segment 'e' connected to Digital Pin 6
#define f 7  // Segment 'f' connected to Digital Pin 7
#define g 8  // Segment 'g' connected to Digital Pin 8
// 7-segment display patterns for digits 0-9 (Common Cathode)
const int digit[10][7] = {
    {1, 1, 1, 1, 1, 1, 0},  // 0
    {0, 1, 1, 0, 0, 0, 0},  // 1
    {1, 1, 0, 1, 1, 0, 1},  // 2
    {1, 1, 1, 1, 0, 0, 1},  // 3
    {0, 1, 1, 0, 0, 1, 1},  // 4
    {1, 0, 1, 1, 0, 1, 1},  // 5
    {1, 0, 1, 1, 1, 1, 1},  // 6
    {1, 1, 1, 0, 0, 0, 0},  // 7
    {1, 1, 1, 1, 1, 1, 1},  // 8
    {1, 1, 1, 1, 0, 1, 1}   // 9
};
void displayDigit(int num) {
    // Display the digit by setting segment values
    digitalWrite(a, digit[num][0]);
    digitalWrite(b, digit[num][1]);
    digitalWrite(c, digit[num][2]);
    digitalWrite(d, digit[num][3]);
    digitalWrite(e, digit[num][4]);
    digitalWrite(f, digit[num][5]);
    digitalWrite(g, digit[num][6]);
}
void setup() {
    // Configure segment pins as OUTPUT
    for (int i = a; i <= g; i++) {
        pinMode(i, OUTPUT);
    }
}
void loop() {
    for (int i = 0; i < 10; i++) {
        displayDigit(i);  // Show digits 0-9
        delay(1000);      // 1-second delay
    }
}
```
_____________________________________________________________________________________________________________________________________
__4. Title: LCD Interfacing with Arduino uno__

*Objective:* Write an Embedded C  program to interface a 16x2 LCD display with Arduino uno that performs the following tasks:

Display the message "Hello World!" on the first row of the LCD.\
Continuously update the second row with a counter value that increments every second.\
Implement a clear screen feature using a push button that resets the counter and clears the LCD display.

__1. Hardware Components Required:__
 - Microcontroller (MCU) - Arduino Uno (or any other MCU).
 - 16x2 LCD Display – To display text messages.
 - 10kΩ Potentiometer – To adjust LCD contrast.
 - Resistor (10kΩ) – For pull-down resistor (if required).
 - Jumper Wires – For making connections.
 - Breadboard – For circuit assembly.
 - 5V Power Supply – Provided via Arduino or an external source.

__2. Hardware Connections:__

![image](https://github.com/user-attachments/assets/acf54972-c09c-4046-83be-0ccf2e7e7fa7)

Push Button Connection:
 - One terminal to D2 (RESET_BUTTON).
 - Other terminal to GND (using internal pull-up in code).

Potentiometer Connection:
 - VCC (One side) → 5V.
 - GND (Other side) → GND.
 - V0 (Middle Pin) → LCD Pin 3 (V0).

__3. Software Used:__
 - Arduino IDE
 - Proteus 

__4. Working of the Project:__\
System Initialization:
 - The LCD is initialized using lcd.begin(16, 2).
 - The first row displays "Hello World!" as a static message.
 - The push button is configured as INPUT_PULLUP to reset the counter.

Counter Display on LCD:
- The second row of the LCD continuously updates with the counter value.
- The counter increments every second and is displayed dynamically.

Reset Functionality:
- If the push button is pressed (LOW state due to pull-up), the following happens:
- The LCD is cleared.
- The counter resets to 0.
- The message "Hello World!" is displayed again on the first row.
- A debounce delay (200ms) prevents false triggering.

Continuous Execution:
 - The program runs indefinitely, updating the counter every second.
 - The counter values are overwritten properly to avoid display errors.

__Software Simulation:__

![image](https://github.com/user-attachments/assets/24666d8d-1a77-4161-aed0-a902a37dba33)

__Hardware Simulation:__

__Project Code:__
```
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
```
______________________________________________________________________________________________________________________________________
__5. Title: Basic Calculator Using Arduino uno and Keypad with LCD Display__

*Objective:* Write an Embedded C  program to implement a basic calculator that performs the following arithmetic operations using a 4x4 keypad and a 16x2 LCD display:

 - Addition (+)
 - Subtraction (-)
 - Multiplication (*)
 - Division (/)

Functional Requirements:
 - The user should enter the first number.
 - The user should then press an operator key (+, -, *, /).
 - The user should enter the second number.
 - Pressing the ‘#’ key should display the result on the LCD.
 - Pressing the ‘*’ key should clear the display and reset the calculator.

__1. Hardware Components Required:__
 - Microcontroller (MCU) - Arduino Uno (or any other MCU).
 - 16x2 LCD Display – To display user input and results.
 - 4x4 Keypad – For entering numbers and operations.
 - Jumper Wires – For making connections.
 - Breadboard – For circuit assembly.
 - 5V Power Supply – Provided via Arduino or an external source.

__2. Hardware Connections:__
![image](https://github.com/user-attachments/assets/716b8635-3587-4ea6-a29b-a1c0f5731237)

__3. Software Used:__
 - Arduino IDE
 - Proteus 

__4. Working of the Project:__\
System Initialization:
 - The LCD is initialized using lcd.begin(16, 2).
 - The message "Calculator Ready" is displayed for 2 seconds.
 - The Keypad is set up for user input.

User Input and Operation:
 - The user enters the first number.
 - The user presses an operator key (+, -, *, /).
 - The user enters the second number.
 - Pressing the ‘=’ key displays the result on the LCD.

Reset Feature:
 - Pressing the ‘C’ key clears the LCD and resets all values.

Calculation Execution:
 - The entered values and operator are processed using the calculateResult function.
 - If division by zero is attempted, the system returns 0 to prevent errors.

__Software Simulation:__

![image](https://github.com/user-attachments/assets/7a3cc621-df36-40e6-ab20-0ee5d3912fb4)

__Hardware Simulation:__

__Project code:__
```
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
```

______________________________________________________________________________________________________________________________________

__6. Title: DC Motor Control System Using Arduino uno__

*Objective:* Write an Embedded C  program to interface a DC motor with Arduino uno that performs the following tasks:

Use a 3-way switch system to control motor actions:\
Switch 1 → Start the motor in Clockwise direction.\
Switch 2 → Start the motor in Anti-clockwise direction.\
Switch 3 → Stop the motor.

__1. Hardware Components Required:__
 - Microcontroller (MCU) - Arduino Uno (or any other compatible MCU).
 - L298N Motor Driver Module – To drive the DC motor.
 - DC Motor – To be controlled.
 - 3 Push Buttons – To control motor direction and stop.
 - 12V Power Supply – For the motor driver.
 - Breadboard & Jumper Wires – For circuit assembly.

__2. Hardware Connections:__
![image](https://github.com/user-attachments/assets/1ad107ef-eefb-474a-adb7-f514aa75ea26)

__3. Software Used:__
 - Arduino IDE
 - Proteus
   
__4. Working of the Project:__\
System Initialization:
 - The motor driver L298N is configured using pinMode().
 - The switches are configured as inputs with internal pull-up resistors.
 - The motor is initially in the STOP state.

Motor Control Using Switches:
 - Pressing Switch 1 rotates the motor clockwise by setting MOTOR_IN1 = HIGH and MOTOR_IN2 = LOW.
 - Pressing Switch 2 rotates the motor anti-clockwise by setting MOTOR_IN1 = LOW and MOTOR_IN2 = HIGH.
 - Pressing Switch 3 stops the motor by setting both MOTOR_IN1 = LOW and MOTOR_IN2 = LOW.

Functionality Overview:
 - The motor remains in the selected state until another switch is pressed.
 - The motor stops when Switch 3 is pressed.

__Software Simulation:__

![image](https://github.com/user-attachments/assets/c0fbafcc-d8e8-4090-82ce-939b044fcdb7)

__Hardware Simulation:__

__Project Code:__
```
#include <Arduino.h>
// Motor Driver Pins (L298N)
#define MOTOR_IN1 5   // Motor Input 1 (Clockwise)
#define MOTOR_IN2 6   // Motor Input 2 (Anti-clockwise)
#define MOTOR_ENA 9   // Enable Pin for Motor Driver
// Switch Pins
#define SWITCH1 2 // Start Clockwise
#define SWITCH2 3 // Start Anti-clockwise
#define SWITCH3 4 // Stop Motor
void setup() {
    pinMode(MOTOR_ENA, OUTPUT);
    pinMode(MOTOR_IN1, OUTPUT);
    pinMode(MOTOR_IN2, OUTPUT);
    pinMode(SWITCH1, INPUT_PULLUP);
    pinMode(SWITCH2, INPUT_PULLUP);
    pinMode(SWITCH3, INPUT_PULLUP);
    digitalWrite(MOTOR_ENA, HIGH); // Enable the motor driver
    digitalWrite(MOTOR_IN1, LOW);
    digitalWrite(MOTOR_IN2, LOW);
}
void loop() {
    if (digitalRead(SWITCH1) == LOW) { // Clockwise Rotation
        digitalWrite(MOTOR_IN1, HIGH);
        digitalWrite(MOTOR_IN2, LOW);
    } else if (digitalRead(SWITCH2) == LOW) { // Anti-clockwise Rotation
        digitalWrite(MOTOR_IN1, LOW);
        digitalWrite(MOTOR_IN2, HIGH);
    } else if (digitalRead(SWITCH3) == LOW) { // Stop Motor
        digitalWrite(MOTOR_IN1, LOW);
        digitalWrite(MOTOR_IN2, LOW);
    }
}
```
______________________________________________________________________________________________________________________________________

__7. Title: Servo Motor Control Using Arduino uno__

*Objective:* Write an Embedded C program to interface a servo motor with the Arduino uno that performs the following tasks using push buttons:

Button 1 → Move the servo motor to 0° position.\
Button 2 → Move the servo motor to 90° position.\
Button 3 → Move the servo motor to 180° position.\
Display the servo angle on a connected LCD display\

1. Hardware Components Required:
 - Microcontroller (MCU) - Arduino Uno (or any other compatible MCU).
 - Servo Motor (SG90 or MG995) – For angular motion.
 - 16x2 LCD Display – To show servo angle.
 - 3 Push Buttons – To control servo position.
 - 5V Power Supply – To power the components.
 - Breadboard & Jumper Wires – For circuit assembly.

3. Hardware Connections:
![image](https://github.com/user-attachments/assets/3c94f664-ce32-4171-ac19-f9431a4e4a82)

4. Software Used:
 - Arduino IDE
 - Proteus

4. Working of the Project:\
System Initialization:
 - The servo motor is initialized using servoMotor.attach(6).
 - The LCD is configured using lcd.begin(16, 2).
 - The push buttons are configured as inputs with internal pull-up resistors.

Servo Motor Control Using Buttons:
 - Pressing Button 1 moves the servo motor to 0°.
 - Pressing Button 2 moves the servo motor to 90°.
 - Pressing Button 3 moves the servo motor to 180°.

LCD Display Updates:
 - The LCD displays the current servo angle when a button is pressed.
 - The LCD clears before displaying a new angle to ensure proper output visibility.

__Software Simulation:__

![image](https://github.com/user-attachments/assets/4d9250d6-1156-47ef-8cbc-7d1523332480)

__Hardware Simulation:__

__Project Code:__
```
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
```

_____________________________________________________________________________________________________________________________________


