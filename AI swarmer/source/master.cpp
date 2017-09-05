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
//seeks a dingle point
void master::steer(sf::Vector2f target)
{
    sf::Vector2f steering;
    //returns a vector2f that is the total motion force on the object
  steering = myAgent->getSteeringForce(m_sprite.getPosition(), target);
  //how to actually move towards this position pl0x
  m_acceleration = steering;

}
//seeks a full path
void master::seekPath(NodeList* path)
{
    //go to a place, check if you are within a distance from it and then set the seek to the next part

   
    NodeList::iterator It = path->begin();

    while ((*It)->m_previous )
    {
        steer((*It)->circle.getPosition());
        if (findDistFromMe((*It)->circle.getPosition()) < 10)
        {
            It++;
        }
    }
    


}
