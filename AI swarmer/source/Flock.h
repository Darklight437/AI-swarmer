#pragma once
#include "Behavior.h"
class Flock :
    public Behavior
{
public:
    Flock();
    ~Flock();

    //get alist of local boids

    sf::Vector2f calculateForce(sf::Vector2f myPosition, sf::Vector2f targetPosition);
    sf::Vector2f separation();
    sf::Vector2f align();
    sf::Vector2f cohere();
};

