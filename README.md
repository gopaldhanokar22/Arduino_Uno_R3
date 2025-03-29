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
![image](https://github.com/user-attachments/assets/55672a59-e281-442f-a6ff-02eacbd696a1)



__Software Used:__
  1. Arduino IDE
  2. Proteus

__Software Simulation:__

![image](https://github.com/user-attachments/assets/b64a8855-795c-4aec-89c8-a311d32946ee)

__Hardware Simulation:__

![IMG-20250330-WA0003](https://github.com/user-attachments/assets/1efe3a05-1ea4-4193-b10f-6403e2d001f3)

![IMG-20250330-WA0004](https://github.com/user-attachments/assets/0be3fc21-e2b4-482c-b9db-a8bd4e9e3c43)

![IMG-20250330-WA0006](https://github.com/user-attachments/assets/d5daa3c6-7cbe-4c1d-bbd8-cf46e01caed9)

![IMG-20250330-WA0007](https://github.com/user-attachments/assets/b2736d7a-143c-40a8-9b47-62527f8eaf4a)

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
// Define LED pins
const int redLED = 11;    // Red LED connected to pin 9
const int yellowLED = 12; // Yellow LED connected to pin 10
const int greenLED = 13;  // Green LED connected to pin 11
void setup() {
    // Set LED pins as output
    pinMode(redLED, OUTPUT);
    pinMode(yellowLED, OUTPUT);
    pinMode(greenLED, OUTPUT);
}
void loop() {
    // Red LED ON (Stop Signal)
    digitalWrite(redLED, HIGH);
    digitalWrite(yellowLED, LOW);
    digitalWrite(greenLED, LOW);
    delay(5000); // 5 seconds delay
    // Yellow LED ON (Get Ready Signal)
    digitalWrite(redLED, LOW);
    digitalWrite(yellowLED, HIGH);
    digitalWrite(greenLED, LOW);
    delay(2000); // 2 seconds delay
    // Green LED ON (Go Signal)
    digitalWrite(redLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(greenLED, HIGH);
    delay(5000); // 5 seconds delay
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
 - Microcontroller (MCU) - Arduino Uno.
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

![IMG-20250330-WA0001](https://github.com/user-attachments/assets/1856767b-d5e3-4fff-a7bf-bbadebef17c9)

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
 - Microcontroller (MCU) - Arduino Uno.
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
 - Microcontroller (MCU) - Arduino Uno.
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
 - Microcontroller (MCU) - Arduino Uno.
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
 - Microcontroller (MCU) - Arduino Uno 
 - Servo Motor (SG90 ) – For angular motion.
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

__8. Title: Temperature Sensor (LM35) Interfacing with Arduino uno__

*Objective:* Write an Embedded C program to interface an LM35 Temperature Sensor with the Arduino uno that performs the following tasks:

Continuously read the temperature value from the LM35 sensor.\
Display the temperature value on an LCD display or Serial Monitor.

__1. Hardware Components Required:__
 - Microcontroller (MCU) - Arduino Uno 
 - LM35 Temperature Sensor – To measure temperature.
 - 16x2 LCD Display – To display temperature readings.
- 5V Power Supply – To power the components.
- Breadboard & Jumper Wires – For circuit assembly.

__2. Hardware Connections:__
![image](https://github.com/user-attachments/assets/30c05f1e-7de0-405c-9760-69467156f5eb)

__3. Software Used:__
 - Arduino IDE
 - Proteus

__5. Working of the Project:__
 - System Initialization:
 - The LCD is configured using lcd.begin(16, 2).
 - The LM35 temperature sensor is connected to the analog pin A0.

Reading Temperature Data:
 - The LM35 outputs an analog voltage proportional to the temperature.
 - The Arduino reads this analog voltage and converts it into a temperature value using:
![image](https://github.com/user-attachments/assets/3db3495e-e1ca-410e-b9b7-ee581c0bd851)

Displaying Temperature Data:
 - The LCD displays the temperature value in Celsius.
 - The temperature reading updates every second.

__Software Simulation:__
![image](https://github.com/user-attachments/assets/b917bb12-15f8-4602-9557-e266bf23e9a0)

__Project Code:__
```
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
```

____________________________________________________________________________________________________________________________________

__9. Title: DHT11 Temperature and Humidity Sensor Interfacing with Arduino uno__

*Objective:* Write an Embedded C program to interface a DHT11 Temperature and Humidity Sensor with the Arduino uno that performs the following tasks:

Read temperature and humidity data from the DHT11 sensor.\
Display the sensor readings on an LCD display.

__1. Hardware Components Required:__
 - Microcontroller (MCU) - Arduino Uno.
 - DHT11 Temperature & Humidity Sensor – To measure environmental conditions.
 - 16x2 LCD Display – To display sensor readings.
 - 5V Power Supply – To power the components.
 - Resistor (10KΩ) (Optional) – For stable signal transmission.
 - Breadboard & Jumper Wires – For circuit assembly.

__2. Hardware Connections:__
![image](https://github.com/user-attachments/assets/dae84803-4f3e-453e-94ee-61e2d9eb4243)

__3. Software Used:__
 - Arduino IDE
 - Proteus

__4. Working of the Project:__\
System Initialization:
 - The DHT11 sensor is initialized using dht.begin().
 - The LCD is configured using lcd.begin(16, 2).

Reading Sensor Data:
 - The DHT11 sensor outputs temperature and humidity data.
 - The temperature is read using dht.readTemperature().
 - The humidity is read using dht.readHumidity().

Displaying Data on LCD:
 - The temperature (°C) and humidity (%) are displayed on the 16x2 LCD.
 - If the sensor fails to read, the LCD displays “Sensor Error”.
 - The data refreshes every 2 seconds.

__Hardware Simulation:__

__Project Code:__
```
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
```

_____________________________________________________________________________________________________________________________________
__10. Title: Fire Sensor Interfacing with Arduino uno__

*Objective:* Write an Embedded C program to interface a Fire Sensor (Flame Sensor) with the Arduino uno that performs the following tasks:

Detect the presence of fire or flame using the fire sensor.\
Display "Fire Detected" or "No Fire" on an LCD display or Serial Monitor.\
If fire is detected, activate a buzzer or LED alert for warning.

__1. Hardware Components Required:__
 - Microcontroller (MCU) - Arduino Uno.
 - Fire Sensor (Flame Sensor - IR based) – To detect fire or flame presence.
 - Buzzer – To give an alert when fire is detected.
 - 16x2 LCD Display – To display sensor status.
 - 5V Power Supply – To power the components.
 - Resistors (Optional) – For stable signal transmission.
 - Breadboard & Jumper Wires – For circuit assembly.

__2. Hardware Connections:__
![image](https://github.com/user-attachments/assets/674204cb-c1cb-472b-9cf8-b081d405cd82)

__3. Software Used:__
 - Arduino IDE
 - proteus

__4. Working of the Project:__\
System Initialization:
 - The Fire Sensor and LCD are initialized using pinMode() and lcd.begin(16, 2).
 - The Buzzer is set to LOW (Off state) initially.

Fire Detection Logic:
 - The Fire Sensor continuously reads analog values from A0.
 - If sensor value > 500, the system detects fire and:
 - Displays "Fire Detected!" on the LCD.
 - Activates the buzzer (HIGH) as an alert.
 - If sensor value <= 500, the system detects no fire and:
 - Displays "No Fire" on the LCD.
 - Turns off the buzzer (LOW).

Alert System:
 - The buzzer rings continuously when fire is detected.
 - The LCD updates every 500ms to ensure real-time fire monitoring.

__Software Simulation:__
![image](https://github.com/user-attachments/assets/7c39eaef-a21e-450e-982f-ccf9f0f51f7d)

__Hardware Simulation:__

__Project Code:__
```
#include <Arduino.h>
#include <LiquidCrystal.h>
// Fire Sensor and Buzzer Pins
#define FIRE_SENSOR_PIN A0 // Analog pin connected to the fire sensor output
#define BUZZER_PIN 3       // Buzzer pin for alert
// LCD Configuration
LiquidCrystal lcd(7, 8, 9, 10, 11, 12); // LCD Pins
void setup() {
    pinMode(FIRE_SENSOR_PIN, INPUT);
    pinMode(BUZZER_PIN, OUTPUT);
    lcd.begin(16, 2); // Initialize LCD
    lcd.print("Fire Sensor");
    delay(2000);
    lcd.clear();
}
void loop() {
    int sensorValue = analogRead(FIRE_SENSOR_PIN); // Read analog value
    // Fire detection logic (higher voltage typically indicates fire presence)
    if (sensorValue > 500) { // Threshold value may vary with sensor
        lcd.setCursor(0, 0);
        lcd.print("Fire Detected!");
        digitalWrite(BUZZER_PIN, HIGH); // Activate buzzer for alert
    } else {
        lcd.setCursor(0, 0);
        lcd.print("No Fire       ");
        digitalWrite(BUZZER_PIN, LOW); // Deactivate buzzer
    }
    delay(500); // Refresh every 500ms
}
```

____________________________________________________________________________________________________________________________________

__11. Title: LED Blinking__

*Objective:* To understand and implement LED control using a microcontroller by turning it on and off at a fixed interval.

*Description:*\
LED blinking is a basic embedded system project that involves programming a microcontroller to toggle an LED using GPIO pins. A delay function controls the blinking rate, demonstrating digital output control and timing functions.

__1. Hardware Components Required:__
 - Microcontroller (MCU) - Arduino Uno
 - LED – Light Emitting Diode for visual indication
 - Current Limiting Resistor (220Ω - 1kΩ) – To protect the LED from excessive current
 - 5V Power Supply – To power the circuit
 - Breadboard & Jumper Wires – For connections

__2. Hardware Connections:__
![image](https://github.com/user-attachments/assets/996fe292-bbb2-40a3-8561-5b79b0043a1e)

__3. Software Used:__
 - Arduino IDE
 - Proteus

__5. Working of the Project:__\
System Initialization:
 - The LED is connected to Pin 13 of the microcontroller.
 - The pinMode(13, OUTPUT) function sets Pin 13 as an output.

Blinking Logic:
 - The digitalWrite(13, LOW) turns the LED OFF.
 - The delay(5000) keeps it OFF for 5 seconds.
 - The digitalWrite(13, HIGH) turns the LED ON.
 - Another delay(5000) keeps it ON for 5 seconds.
 - The cycle repeats indefinitely.

__Software Simulation:__

![image](https://github.com/user-attachments/assets/93ed8ccc-6932-4c53-85ac-836d9231ff22)

__Hardware Simulation:__

![IMG-20250330-WA0002](https://github.com/user-attachments/assets/9aa30c7b-8f0c-4cd2-b4ad-2b7a55c0fb01)

![IMG-20250330-WA0005](https://github.com/user-attachments/assets/42d5b634-a637-47e2-8e3c-aed8cec362e0)


__Project Code:__
```
void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
 digitalWrite(13, LOW);
 delay(5000);
 digitalWrite(13, HIGH);
 delay(5000);
}
```

______________________________________________________________________________________________________________________________________

__12. Title: Sharp Distance Sensor Interfacing with Arduino uno__

*Objective:* Write an Embedded C program to interface a Sharp Distance Sensor with the Arduino uno that performs the following tasks:

Continuously read the distance value from the Sharp Distance Sensor.\
Display the distance value (in cm) and voltage (in V) on an LCD display.

__1. Hardware Components Required:__
 - Microcontroller (MCU) - Arduino Uno.
 - Sharp IR Distance Sensor (e.g., GP2Y0A21YK) – To measure distance
 - 16x2 LCD Display – To display distance and voltage values
 - 10KΩ Potentiometer – For LCD contrast adjustment
 - Connecting Wires – For interfacing components
 - 5V Power Supply – To power the system

__2. Hardware Connections:__
![image](https://github.com/user-attachments/assets/7e4057d7-4a0c-40b2-aad0-5407609b3c27)

__3. Software Used:__
 - Arduino IDE
 - Proteus

__5. Working of the Project:__\
System Initialization:
 - The Sharp Distance Sensor is connected to analog pin A0.
 - The 16x2 LCD is initialized for displaying values.

Reading the Sensor:
 - The analogRead(SENSOR_PIN) reads the voltage output from the sensor.
 - The voltage is converted to a distance value using a mathematical formula.

Displaying the Data:
 - The LCD shows the distance in cm.
 - The LCD also shows the corresponding sensor output voltage.
 - The values update every 500ms.

__Software Simulation:__

![image](https://github.com/user-attachments/assets/01da851f-b479-4677-b7de-3f4dbd0bae8d)

__Project Code:__
```
#include <Arduino.h>
#include <LiquidCrystal.h>
// Sharp Distance Sensor and Buzzer Pins
#define SENSOR_PIN A0 // Analog pin connected to the Sharp sensor output
// LCD Configuration
LiquidCrystal lcd(7, 8, 9, 10, 11, 12); // LCD Pins
void setup() {
    pinMode(SENSOR_PIN, INPUT);
    lcd.begin(16, 2); // Initialize LCD
    lcd.print("Sharp Sensor");
    delay(2000);
    lcd.clear();
}
void loop() {
    int sensorValue = analogRead(SENSOR_PIN); // Read analog value
    float voltage = sensorValue * (5.0 / 1023.0); // Convert to voltage
    // Distance estimation formula (varies by sensor model)
    float distance = 27.86 * pow(voltage, -1.15); // Sample equation for GP2Y0A21YK sensor
    lcd.setCursor(0, 0);
    lcd.print("Dist: ");
    lcd.print(distance);
    lcd.print(" cm ");
    lcd.setCursor(0, 1);
    lcd.print("Volt: ");
    lcd.print(voltage);
    lcd.print(" V");
    delay(500); // Refresh every 500ms
}
```
____________________________________________________________________________________________________________________________________

__13. Title: Ultrasonic Sensor (HC-SR04) Interfacing with Arduino uno__

*Objective:* Write an Embedded C program to interface an Ultrasonic Sensor (HC-SR04) with the Arduino uno that performs the following tasks:

Measure the distance of an object in centimeters (cm) using the ultrasonic sensor.
Display the measured distance on an LCD display or Serial Monitor.\
If the detected distance is less than 10 cm, activate a buzzer or LED alert for warning.

__1. Hardware Components Required:__
 - Microcontroller (MCU) - Arduino uno.
 - Ultrasonic Sensor (HC-SR04) – To measure object distance
 - 16x2 LCD Display – To display distance values
 - Buzzer – For alerting when distance is below 10 cm
 - 10KΩ Potentiometer – For LCD contrast adjustment
 - Connecting Wires – For interfacing components
 - 5V Power Supply – To power the system

__2. Hardware Connections:__
![image](https://github.com/user-attachments/assets/1ce24422-0169-4bf3-a8ef-399f9aed6612)

__3. Software Used:__
 - Arduino IDE
 - Proetus

__5. Working of the Project:__\
System Initialization:
 - The HC-SR04 ultrasonic sensor is connected to pins 2 (Trig) and 3 (Echo).
 - The LCD display is initialized for distance output.
 - The Buzzer is connected to pin 4.

Measuring Distance:
 - The Trig pin is pulsed HIGH for 10µs.
 - The Echo pin receives the reflected signal.
 - The pulse duration is converted to distance using the speed of sound.

Displaying the Data:
 - The LCD shows the measured distance in cm.
 - If the distance is below 10 cm, the buzzer is activated.
 - The LCD displays an "ALERT: Object!" message.

__Software Simulation:__

![image](https://github.com/user-attachments/assets/f292163a-008b-4fac-9508-82090c11793c)


__Hardware Simulation:__


__Project Code:__
```
#include <Arduino.h>
#include <LiquidCrystal.h>
// Ultrasonic Sensor Pins
#define TRIG_PIN 2
#define ECHO_PIN 3
#define BUZZER_PIN 4
// LCD Configuration
LiquidCrystal lcd(7, 8, 9, 10, 11, 12); // LCD Pins
void setup() {
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
    pinMode(BUZZER_PIN, OUTPUT);
    lcd.begin(16, 2); // Initialize LCD
    lcd.print("Ultrasonic Sensor");
    delay(2000);
    lcd.clear();
}
float getDistance() {
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);
    long duration = pulseIn(ECHO_PIN, HIGH);
    float distance = (duration * 0.034) / 2; // Distance in cm
    return distance;
}
void loop() {
    float distance = getDistance();
    lcd.setCursor(0, 0);
    lcd.print("Dist: ");
    lcd.print(distance);
    lcd.print(" cm ");
    if (distance < 10) {
        digitalWrite(BUZZER_PIN, HIGH);
        lcd.setCursor(0, 1);
        lcd.print("ALERT: Object! ");
    } else {
        digitalWrite(BUZZER_PIN, LOW);
        lcd.setCursor(0, 1);
        lcd.print("                "); // Clear alert line
    }
    delay(500); // Refresh every 500ms
}
```

-------------------------------------------------------------------------------------------------------------------------------------
