#pragma once

#include <SFML\System\Clock.hpp>

class deltaClock
{
public:
    deltaClock();
    ~deltaClock();
    //returns the elapsed time since last update
    sf::Time restart();
    sf::Time getelapsedTime();

private:
    sf::Clock timer;


};

