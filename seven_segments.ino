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
