#include <Arduino.h>
#include "ArduinoMetronome.hpp"

ArduinoMetronome metronomeA(1000);  //Setup interval A in constructor 
ArduinoMetronome metronomeB;        //Setup interval B later

void setup() {
  Serial.begin(115200);

  metronomeB.intervalSet(500);      //Setup interval B
}

void loop() {
  if(metronomeA.loopMs())
  {
    Serial.println("A: " + String(millis()) + "  Interval: " + String(metronomeA.intervalGet()));
  }


  if(metronomeB.loopMs())
  {
    Serial.println("B: " + String(millis()) + "  Interval: " + String(metronomeB.intervalGet()));
  } 
}