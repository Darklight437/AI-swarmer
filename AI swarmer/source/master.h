#pragma once
#include "Gameobject.h"
#include "Agent.h"
class master :
    public Gameobject
{
public:
    
    void loadSprite();
    
    master();
    ~master();
    void steer(sf::Vector2f target);

private:
    Agent* myAgent;
};

