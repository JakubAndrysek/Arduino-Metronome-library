# BasicMetronome-Arduino-library
Library for easy timing without `delay()`

### One metronome
```cpp
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
```

### Multi metronomes
```cpp
#include <Arduino.h>
#include "ArduinoMetronome.hpp"

ArduinoMetronome metronomeA(1000);  //Setup interval A in constructor 
ArduinoMetronome metronomeB;        //Setup interval B later
ArduinoMetronome metronomeC;        //Setup interval C later

void setup() {
  Serial.begin(115200);

  metronomeB.setInterval(500);      //Setup interval B
}

void loop() {
  if(metronomeA.loopMs())
  {
    Serial.println("A: " + String(millis()) + "  Interval: " + String(metronomeA.getInterval()));
  }


  if(metronomeB.loopMs())
  {
    Serial.println("B: " + String(millis()) + "  Interval: " + String(metronomeB.getInterval()));
  }


  if(metronomeC.loopMs(5000))       //In place setup interval
  {
    Serial.println("C: " + String(millis()) + "  Interval: " + String(metronomeC.getInterval()));
  }  
}
```
