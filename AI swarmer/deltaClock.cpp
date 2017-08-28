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

sf::Time deltaClock::restart()
{
    sf::Time elapsedTime = timer.restart();
    return elapsedTime;
}

sf::Time deltaClock::getelapsedTime()
{
    sf::Time elapsedTime = timer.getElapsedTime();
    return elapsedTime;
} 
