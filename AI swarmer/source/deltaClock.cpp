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
    return TimeForFrame.asSeconds();
}

double deltaClock::getelapsedTime()
{
    // gets time since last restart
    //is this ok?
    //probably a hack

    /*if (TimeForFrame.asMilliseconds() > 16)
    {
        TimeForFrame = sf::milliseconds(16);
    }*/
    double DT = TimeForFrame.asSeconds();
    if (DT > 0.1f)
    {
        DT = 0.1f;
    }
    return DT;
} 
