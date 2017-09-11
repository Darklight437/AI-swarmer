#pragma once
#include "Behavior.h"
#include <list>
#include "Swarmer.h"
class Flock :
    public Behavior
{
public:
    Flock();
    ~Flock();

    //get alist of local boids

    sf::Vector2f calculateForce(sf::Vector2f myPosition, std::list<Swarmer*>neighbours);
    sf::Vector2f separation();
    sf::Vector2f align();
    sf::Vector2f cohere();
};

