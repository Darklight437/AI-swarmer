#include "master.h"
#include"Behavior.h"
#include "Seek.h"
#include "Pathing_Walker.h"

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

void master::steer(sf::Vector2f target)
{
    sf::Vector2f steering;
    //returns a vector2f that is the total motion force on the object
  steering = myAgent->getSteeringForce(m_sprite.getPosition(), target);
  //how to actually move towards this position pl0x
  m_acceleration = steering;

}

void master::seekPath(Pathing_node * firstElement)
{
    //go to a place, check if you are within a distance from it and then set the seek to the next part
}
