#pragma once
#include "Behavior.h"
#include<SFML\Graphics\Transformable.hpp>
#include "deltaClock.h"

class Seek :
    public Behavior
{
public:
    Seek();
    ~Seek();
    //Find(sf::Vector2f myPosition);
    sf::Vector2f calculateForce(sf::Vector2f myPosition, sf::Vector2f targetPosition);

private:

    sf::Vector2f steeringForce;
    float seekspeed = 2;

};

