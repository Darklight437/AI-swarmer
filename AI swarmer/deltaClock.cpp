#include "deltaClock.h"



deltaClock::deltaClock()
{
}


deltaClock::~deltaClock()
{
}

deltaClock * deltaClock::instance()
{
    if (!s_instance)
    {
        s_instance = new deltaClock;
        return s_instance;
    }
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
