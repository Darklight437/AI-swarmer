#pragma once
#include "Behavior.h"
#include<SFML\Graphics\Transformable.hpp>


class Seek :
    public Behavior
{
public:
    Seek();
    ~Seek();
    //Find(sf::Vector2f myPosition);
    sf::Vector2f calculateForce();

private:
    sf::Vector2f myPos;
    sf::Vector2f steeringForce;
    float seekspeed = 5;

};

