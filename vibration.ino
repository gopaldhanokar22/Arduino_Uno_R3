#define LED 3
#define Sensor 2
void setup() {
  Serial.begin(9600);
  pinMode(Sensor, INPUT);
  pinMode(LED, OUTPUT);
}
void loop() {
  bool value = digitalRead(Sensor);
  if (value == 1) {
    digitalWrite(LED,HIGH);
  }else if(value == 0){
    digitalWrite(LED,LOW);
  }
}