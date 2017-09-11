#pragma once
//#include <SFML\Graphics\Transformable.hpp>
#include <vector>
#include "Behavior.h"
#include "Seek.h"
#include "Flock.h"


class Agent
{
public:
    Agent();
    ~Agent();
    
    sf::Vector2f getSteeringForce(sf::Vector2f myPosition, sf::Vector2f targetPosition);
    
    

    Behavior* seekBehavior = new Seek;
    Behavior* FlockBehavior = new Flock;
    
    sf::Vector2f steeringForce;
    bool seek = false;
    bool flock = false;
    std::list<Swarmer*> flockingNeighbours;
};

