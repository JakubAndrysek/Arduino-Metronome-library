#include <Arduino.h>
#include "ArduinoMetronome.hpp"

ArduinoMetronome metronome1(1000);

void setup() {
  Serial.begin(115200);
  
  metronome1.startupDelayMs(3000);
  Serial.println("Metronome1 waits 3000 ms");
}

void loop() {
  if(metronome1.loopMs())
  {
    Serial.println(millis());
  }
}