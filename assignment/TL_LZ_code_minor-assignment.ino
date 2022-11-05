// MOTOR
#define MOTOR_PIN_A 10
#define MOTOR_PIN_B 2
#define MOTOR_PIN_C 6
#define MOTOR_PIN_D 7
#define MOTOR_PIN_E 8
#define MOTOR_PIN_F 9

int speed = 100;
int slowspeed = 60;
int colVal = 0;
int ledMode = 0;
int randTime = 4000;
int randDir = 0;
unsigned long myTime;


// SENSOR DISTANCE

#include <Wire.h>
#include "Adafruit_VL6180X.h"

Adafruit_VL6180X vl = Adafruit_VL6180X();

#include "SparkFun_VCNL4040_Arduino_Library.h"
VCNL4040 proximitySensor;

// LEDs

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

#define PIN 0
#define NUMPIXELS 8

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);


void setup() {
  Serial.begin(9600);

  pixels.begin();


  // SENSOR
  if (! vl.begin()) {
    Serial.println("Failed to find sensor");
    while (1);
  }
  Serial.println("Sensor found!");


  pinMode(MOTOR_PIN_A, OUTPUT);
  pinMode(MOTOR_PIN_B, OUTPUT);
  pinMode(MOTOR_PIN_C, OUTPUT);
  pinMode(MOTOR_PIN_D, OUTPUT);
  pinMode(MOTOR_PIN_E, OUTPUT);
  pinMode(MOTOR_PIN_F, OUTPUT);

  Serial.println("TEST");

  // SECOND
  Wire.begin(); //Join i2c bus

  if (proximitySensor.begin() == false)
  {
    Serial.println("Device not found. Please check wiring.");
    while (1); //Freeze!
  }

}


void loop() {
      // TIMING
      myTime = millis();

      // LED FADING
      if(ledMode==0){
        colVal = colVal + 2;
      }else{
        colVal = colVal - 2;
      }
      if(colVal>100){
        ledMode = 1;
      }else if(colVal<2){
        ledMode = 0;
      }

      // SENSOR
      uint8_t range = vl.readRange();

      //Serial.println(range);

      // SECOND SENSOR
      unsigned int proxValue = proximitySensor.getProximity(); 
/*
      Serial.print("Proximity Value: ");
      Serial.print(proxValue);
      Serial.println();*/

      if(proxValue>1200){
        for(int i=0; i<NUMPIXELS; i++) {
          pixels.setPixelColor(i, pixels.Color(0, colVal, 0));
        }
        analogWrite(MOTOR_PIN_A, 0); // 2 SPEED
        analogWrite(MOTOR_PIN_B, 0); // 3
        analogWrite(MOTOR_PIN_C, 0); // 6
        analogWrite(MOTOR_PIN_D, 0); // 7
        analogWrite(MOTOR_PIN_E, 0); // 8 SPEED
        analogWrite(MOTOR_PIN_F, 0); // 9        
      }
      else if (range<160) {
        
        for(int i=0; i<NUMPIXELS; i++) {
          pixels.setPixelColor(i, pixels.Color(50, 0, 0));
        }
        analogWrite(MOTOR_PIN_A, speed); // 2 SPEED
        analogWrite(MOTOR_PIN_B, speed);// 3
        analogWrite(MOTOR_PIN_C, 0);// 6
        analogWrite(MOTOR_PIN_D, 0);// 7
        analogWrite(MOTOR_PIN_E, speed); // 8 SPEED
        analogWrite(MOTOR_PIN_F, speed); // 9     
        } 
      else {
        for(int i=0; i<NUMPIXELS; i++) {
          pixels.setPixelColor(i, pixels.Color(0, 0, colVal));
        }

        //Serial.println(myTime%4000>200);
        if(myTime%4000<50){
          randomTime();
        }
        // DRIVING OF CAR
        chooseDirection(randDir);
      }
      pixels.show();
}

void randomTime(){
      randTime = random(2, 10)*1000;
      randDir = round(random(3));
      Serial.println(randDir);
      for(int i=0; i<NUMPIXELS; i++) {
          pixels.setPixelColor(i, pixels.Color(50, 50, 0));
      }
}

void chooseDirection(int val){
    if(val==0){ // STRAIGHT
        analogWrite(MOTOR_PIN_A, speed); // 2 SPEED
        analogWrite(MOTOR_PIN_E, speed); // 8 SPEED
    }else if(val==1){ // LEFT
        analogWrite(MOTOR_PIN_A, slowspeed); // 2 SPEED
        analogWrite(MOTOR_PIN_E, speed); // 8 SPEED
    }else if(val==2){ // RIGHT
        analogWrite(MOTOR_PIN_A, speed); // 2 SPEED
        analogWrite(MOTOR_PIN_E, slowspeed); // 8 SPEED
    }
    analogWrite(MOTOR_PIN_B, 0);// 3
    analogWrite(MOTOR_PIN_C, speed);// 6
    analogWrite(MOTOR_PIN_D, 0);// 7
    analogWrite(MOTOR_PIN_F, speed); // 9
}
