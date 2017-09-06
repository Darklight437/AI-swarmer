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

    void setPath(NodeList newPath);
    void seekPath();

private:
    NodeList path;
    Pathing_node* currTarget;
    bool following = false;
};

