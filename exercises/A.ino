#define inputPin A0
#define ledPin 11


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(inputPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int pinValue = analogRead(inputPin);
  int speed = map(pinValue, 0, 1024, 0, 255);
  
  analogWrite(ledPin,speed);
  Serial.println(pinValue);
}
