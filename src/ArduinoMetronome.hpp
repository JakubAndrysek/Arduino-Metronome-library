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
    int counterNow = 0;
    int counterMax = 0;
    
public:
    ArduinoMetronome(int interval, int countMax = 0);
    ArduinoMetronome();
    
    void intervalSet(int interval);
    int intervalGet();
    
    void startupDelayMs(int millis);
    
    void counterMaxSet(int countMax);
    int counterMaxGet();
    
    void counterNowIncrease();
    int counterNowGet();
    void counterNowReset();

    bool counterLoop();
    bool incCounterLoop();
    bool loopMs();
    bool loopMsCounter();
  

};


