#pragma once
#include "Gameobject.h"
#include <list>
class Swarmer :
    public Gameobject
{
public:
    Swarmer();
    ~Swarmer();

    void loadSprite();
    void updateNeighbours(std::list<Swarmer*>neighbours);


private:
    std::list<Swarmer*> m_neighbours;
    Agent myAgent;
    
};

