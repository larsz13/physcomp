#include <Wire.h>
#include "Adafruit_VL6180X.h"

Adafruit_VL6180X vl = Adafruit_VL6180X();

#define ledPIN 11

void setup() {
  Serial.begin(9600);
  if (! vl.begin()) {
    Serial.println("Failed to find sensor");
    while (1);
  }
  Serial.println("Sensor found!");
}

void loop() {
  uint8_t range = vl.readRange();
  int intensity = map(range,13,255,0,255);
  Serial.println(intensity);
  analogWrite(ledPIN,intensity);
}
