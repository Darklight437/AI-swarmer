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
    sf::Time elapsedTime = timer.restart();
    return elapsedTime.asMilliseconds();
}

double deltaClock::getelapsedTime()
{
    sf::Time elapsedTime = timer.getElapsedTime();
    return elapsedTime.asMilliseconds();
} 
