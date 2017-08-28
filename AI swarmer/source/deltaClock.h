#pragma once

#include <SFML\System\Clock.hpp>
#define CLOCK deltaClock::getInstance()


class deltaClock
{
public:
    //use the sfml clock to just check when it is called


    static deltaClock *getInstance();



    //returns the elapsed time since last update
    double restart();
    double getelapsedTime();

private:
    sf::Clock timer;
    sf::Time TimeForFrame;
    deltaClock();
    ~deltaClock();

};

