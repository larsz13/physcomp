
// PIXELS
#include <Wire.h>
#include "Adafruit_VL6180X.h"
Adafruit_VL6180X vl = Adafruit_VL6180X();
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif
#define PIN 11
#define NUMPIXELS 8
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

// POTENTIOMETER
#define inputPot A0

// BUTTON 
#define inputBut 2
int state = 1;
int stateNumber = 0;

void setup() {
  Serial.begin(9600);

  pinMode(inputBut,INPUT_PULLUP);

  // PIXELS
  pixels.begin();
}

void loop() {
  
  // POTENTIOMETER
  int potentVal = analogRead(inputPot);
  int colorVal = map(potentVal,0,1024,0,255);

  // CHANGE ON BUTTON CLICK
  int buttonVal = digitalRead(inputBut);
  if(buttonVal==0){
    if(stateNumber==7){
        stateNumber=0;
      }else{
        stateNumber = stateNumber+1;
      }
    if(state==0){
      state=1;
    }else if(state==1){
      state=0;
      }
      delay(500);
    }
    

  // PIXELS
  pixels.clear();
  for(int i=0;i<=stateNumber;i++){
      pixels.setPixelColor(i, pixels.Color(0, 0, colorVal));
    }
  pixels.show();
}
