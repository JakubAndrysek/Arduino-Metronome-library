
#include "ArduinoMetronome.hpp"

/**
 * @brief Construct a new Arduino Metronome:: Arduino Metronome object
 * 
 * @param interval in ms
 */
ArduinoMetronome::ArduinoMetronome(int interval)
{
    tInterval = interval;
    lastTime = millis();
}

/**
 * @brief Construct a new Arduino Metronome:: Arduino Metronome object
 * 
 */
ArduinoMetronome::ArduinoMetronome()
{
    lastTime = millis();
}

/**
 * @brief Set metronome inteval
 * 
 * @param interval in ms
 */
void ArduinoMetronome::setInterval(int interval)
{
    tInterval = interval;
}

/**
 * @brief Get metronome interval
 * 
 * @return int 
 */
int ArduinoMetronome::getInterval()
{
    return tInterval;
}

/**
 * @brief Metronome loop
 *  
 * @return bool
 */
bool ArduinoMetronome::loopMs()
{
    nowTime = millis();

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

/**
 * @brief Metronome loop (custom interval)
 * 
 * @param interval in ms 
 * @return bool 
 */
bool ArduinoMetronome::loopMs(int interval)
{
    nowTime = millis();

    if(nowTime >= (lastTime + interval))
    {
        lastTime = nowTime;
        return true;
    }
    else
    {
        return false;
    }
        
}


