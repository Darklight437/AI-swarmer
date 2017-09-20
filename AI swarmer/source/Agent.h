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
    sf::Vector2f getFlockForce(Gameobject* thisObject, sf::Vector2f targetPos);
    void addNeighbour(Gameobject* thisSwarmer);
    void removeNeighbour(Gameobject* thisSwarmer);
    void setTopSpeed(float speed);

    Behavior* seekBehavior = new Seek;
    Behavior* FlockBehavior = new Flock;
    
private:
    float movementSpeed;
    sf::Vector2f steeringForce;
    std::list<Gameobject*> flockingNeighbours;
};

