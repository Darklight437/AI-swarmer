#pragma once
#include "Behavior.h"
#include <list>


class Gameobject;
//class Agent;

class Flock :
    public Behavior
{
public:
    Flock();
    ~Flock();

    //get alist of local boids
    //satisfy the default setup somehow
    sf::Vector2f calculateForce(sf::Vector2f myPosition, sf::Vector2f targetPosition, float speed);
    sf::Vector2f calculateForce(Gameobject* thisObject, Agent::FlockingNeighbours neighbourhood, sf::Vector2f targetPos);
    sf::Vector2f separation(sf::Vector2f myPosition, sf::Vector2f neighbourPos);
    sf::Vector2f align(sf::Vector2f neighbourPos);
    sf::Vector2f cohere(sf::Vector2f myPosition, sf::Vector2f neighbourPos);
    std::list<Gameobject*> getNeighbours(Gameobject* thisSwarmer);
private:
    float cohesionWeight = 0.4f;
    float alignWeight = 0.5f;
    float separateWeight = 0.9f;
};

