#pragma once
#include "Behavior.h"
class Flock :
    public Behavior
{
public:
    Flock();
    ~Flock();

    sf::Vector2f calculateForce(sf::Vector2f myPosition, sf::Vector2f targetPosition);
};

