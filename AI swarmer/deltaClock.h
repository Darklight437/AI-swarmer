#pragma once

#include <SFML\System\Clock.hpp>
#define CLOCK deltaclock::getInstance()


class deltaClock
{
public:


    static deltaClock *getInstance();



    //returns the elapsed time since last update
    sf::Time restart();
    sf::Time getelapsedTime();

private:
    sf::Clock timer;
    deltaClock();
    ~deltaClock();

};

