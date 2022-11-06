#define inputPin A0
#define ledPin 11
int state = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(inputPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int pinValue = analogRead(inputPin);
  int ledValue = map(pinValue, 15, 100, 80, 0);
  Serial.print("pin input:");
  Serial.println(pinValue);
  analogWrite(ledPin,ledValue);
  delay(50);
}
