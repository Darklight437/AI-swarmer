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
   
   
}


master::~master()
{
    delete myAgent;
}

void master::seekTarget(sf::Vector2f target)
{
    myAgent->getSteeringForce(m_position, target);
}
