#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif
#define PIN 11
#define NUMPIXELS 8
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
#define DELAYVAL 500
 
#define ledPIN 11

void setup() {
  Serial.begin(9600);
  pixels.begin();
}

void loop() {
  uint8_t range = vl.readRange();
  for(int i=0;i>7;i++){
    if(i%4==0){
      pixels.setPixelColor(i, pixels.Color(200, 0, 0));
    }else if(i%4==1){
      pixels.setPixelColor(i, pixels.Color(0, 200, 0));
    }else if(i%4==2){
      pixels.setPixelColor(i, pixels.Color(0, 0, 200));
    }else if(i%4==3){
      pixels.setPixelColor(i, pixels.Color(0, 200, 200));
    }
  }
  pixels.show();
}
