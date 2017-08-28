#pragma once

#include <SFML\System\Clock.hpp>

class deltaClock
{
public:

    static deltaClock *s_instance;

    static deltaClock *instance();



    //returns the elapsed time since last update
    sf::Time restart();
    sf::Time getelapsedTime();

private:
    sf::Clock timer;
    deltaClock();
    ~deltaClock();

};

