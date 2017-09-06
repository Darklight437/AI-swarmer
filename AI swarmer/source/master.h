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
    void setPath(NodeList newPath);
    void seekPath();

private:
    Agent* myAgent;
    NodeList path;
    Pathing_node* currTarget;
    bool following = false;
};

