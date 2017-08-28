#include "deltaClock.h"



deltaClock::deltaClock()
{
}


deltaClock::~deltaClock()
{
}



deltaClock * deltaClock::getInstance()
{
    static deltaClock clock;
    return&clock;
}

double deltaClock::restart()
{
    TimeForFrame = timer.restart();
    return TimeForFrame.asMilliseconds();
}

double deltaClock::getelapsedTime()
{
    // gets time since last restart
    //is this ok?
    TimeForFrame = timer.getElapsedTime();
    return TimeForFrame.asMilliseconds();
} 
