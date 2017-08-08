#pragma once
#include "SFML\Graphics.hpp"
class Behavior
{
public:
    Behavior();
    virtual ~Behavior();

    sf::Vector2f Force;

protected:
    virtual sf::Vector2f calculateForce() = 0;



};

