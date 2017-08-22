#include "master.h"
#include"Behavior.h"
#include "Seek.h"

void master::loadSprite()
{
    m_texture.loadFromFile((getExecutableFolder() + "/sprites/rocket-drone.png").c_str());
    m_texture.setSmooth(false);
    m_sprite.setTexture(m_texture);
}

master::master()
{
   loadSprite();
   myAgent = new Agent;

   myAgent->behaviors.push_back();
}


master::~master()
{
    delete myAgent;
}
