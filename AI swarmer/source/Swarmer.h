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
    void getNeighbours(std::list<Swarmer*>neighbours);


private:
    std::list<Swarmer*> m_neighbours;
};

