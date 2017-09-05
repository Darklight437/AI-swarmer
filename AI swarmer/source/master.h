#pragma once
#include "Gameobject.h"
#include "Agent.h"
#include "Pathing_Walker.h"
class master :
    public Gameobject
{
public:
    
    void loadSprite();
    
    master();
    ~master();
    void steer(sf::Vector2f target);
    void seekPath(NodeList* firstElement);

private:
    Agent* myAgent;
};

