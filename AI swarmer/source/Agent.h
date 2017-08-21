#pragma once
//#include <SFML\Graphics\Transformable.hpp>
#include <vector>
#include "Behavior.h"


class Agent
{
public:
    Agent();
    ~Agent();
    
    sf::Vector2f getSteeringForce();
    
    

    std::vector<Behavior*> behaviors;
    sf::Vector2f steeringForce;
};

