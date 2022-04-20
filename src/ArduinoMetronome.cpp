
#include "ArduinoMetronome.hpp"

/**
 * @brief Construct a new Arduino Metronome:: Arduino Metronome object
 * 
 * @param interval in ms
 */
ArduinoMetronome::ArduinoMetronome(int interval, int countMax)
{
    tInterval = interval;
    lastTime = millis();
    counterNow = 0;
    counterMax = countMax;
}

/**
 * @brief Construct a new Arduino Metronome:: Arduino Metronome object
 * 
 */
ArduinoMetronome::ArduinoMetronome()
{
    lastTime = millis();
    counterNow = 0;
}

/**
 * @brief Set metronome inteval
 * 
 * @param interval in ms
 */
void ArduinoMetronome::intervalSet(int interval)
{
    tInterval = interval;
}

/**
 * @brief Get metronome interval
 * 
 * @return int 
 */
int ArduinoMetronome::intervalGet()
{
    return tInterval;
}

////////////////////////////////////////////////////////////////////

void ArduinoMetronome::timeReset()
{
    lastTime = millis();
}

////////////////////////////////////////////////////////////////////


void ArduinoMetronome::counterMaxSet(int countMax) {
    counterMax = counterMax;
}

int ArduinoMetronome::counterMaxGet() {
    return counterMax;
}

/**
 * @brief Reset counter to 0
 * 
 */
void ArduinoMetronome::counterNowReset() {
    counterNow = 0;
}

int ArduinoMetronome::counterNowGet() {
    return counterNow;
}

/**
 * @brief Increase actual counter by 1
 * 
 */
void ArduinoMetronome::counterNowIncrease() {
    ++counterNow;
}

bool ArduinoMetronome::counterLoop() {
    if(counterNow <= counterMax) {
        return true;
    }

    return false;
}

bool ArduinoMetronome::incCounterLoop() {
    counterNowIncrease();
    return counterLoop();
}

// void ArduinoMetronome::

/**
 * @brief Metronome loop
 *  
 * @return bool
 */
bool ArduinoMetronome::loopMs()
{    
    nowTime = millis();

    if(nowTime<startupDelay)
    {
        return false;
    }

    if(nowTime >= (lastTime + tInterval))
    {
        lastTime = nowTime;
        return true;
    }
    else
    {
        return false;
    }
        
}

bool ArduinoMetronome::loopMsCounter() {
    return loopMs() && incCounterLoop();
}

/**
 * @brief Metronome starts after setuped delay
 * 
 * @param ms 
 */
void ArduinoMetronome::startupDelayMs(int ms)
{
    startupDelay = ms;
    startupDelayNow = millis();
}




