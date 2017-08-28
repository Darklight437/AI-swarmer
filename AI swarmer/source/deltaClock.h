#pragma once

#include <SFML\System\Clock.hpp>
#define CLOCK deltaClock::getInstance()


class deltaClock
{
public:


    static deltaClock *getInstance();



    //returns the elapsed time since last update
    double restart();
    double getelapsedTime();

private:
    sf::Clock timer;
    deltaClock();
    ~deltaClock();

};

