#pragma once
//#include <SFML\Graphics\Transformable.hpp>
#include <vector>
#include "Behavior.h"
#include "Seek.h"


class Agent
{
public:
    Agent();
    ~Agent();
    
    sf::Vector2f getSteeringForce();
    
    

    Behavior* seekBehavior = new Seek;
    
    
    sf::Vector2f steeringForce;
};

