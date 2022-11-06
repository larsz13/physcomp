#include <Servo.h>

#define OUTPUT_PIN 11
const int DELAY_MS = 200;
int inputVal; 

Servo myservo;

void setup() {
  Serial.begin(9600);
  pinMode(OUTPUT_PIN, OUTPUT);
  myservo.attach(11);
}

void loop() {
  // Check to see if there is any incoming serial data
  if (Serial.available() > 0) {
    // read string until the endo of the line
    String rcvdSerialData = Serial.readStringUntil('\n');
    analogWrite(OUTPUT_PIN, rcvdSerialData.toInt());
    //delay(DELAY_MS);
    myservo.write(140);
    //Serial.println("Data received"+rcvdSerialData.toInt());
  }

  //int servoVal = map(valu,0,1024,180,0);
  //myservo.write(servoVal); 
  
}
