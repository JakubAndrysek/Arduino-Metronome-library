#include <Arduino.h>
#include "ArduinoMetronome.hpp"

ArduinoMetronome metronome1(1000);

void setup() {
  Serial.begin(115200);
}

void loop() {
  if(metronome1.loopMs())
  {
    Serial.println(millis());
  }
}