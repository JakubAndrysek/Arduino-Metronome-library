#pragma once

#include <Arduino.h>


class ArduinoMetronome
{
private:
    int tInterval = 1000;
    int lastTime = 0;
    int nowTime = 0;
    int startupDelay = 0;
    int startupDelayNow = 0;
    
public:
    ArduinoMetronome(int interval);
    ArduinoMetronome();
    void setInterval(int interval);
    int getInterval();
    bool loopMs(int interval);
    bool loopMs();
    void startupDelayMs(int millis);
  

};


