#include "master.h"
#include"Behavior.h"
#include "Seek.h"
#include "Pathing_Walker.h"
#include "Vmath.h"


void master::loadSprite()
{
    m_texture.loadFromFile((getExecutableFolder() + "/sprites/rocket-drone.png"));
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
  
  setRotation(angleOfVect(steering));

}
//seeks a full path
void master::setPath(NodeList newPath)
{
    //go to a place, check if you are within a distance from it and then set the seek to the next part
    path = newPath;
    currTarget = path.front();
    setPosition(currTarget->getPos());

    following = true;
}

void master::seekPath()
{
    if (following == true)
    {
        steer(currTarget->getPos());

        if (findDistFromMe(currTarget->getPos()) < 10)
        {
            if (currTarget == path.back())
            {
                currTarget = path.front();
                setPosition(currTarget->getPos());
            }
            else
            {
                currTarget = currTarget->m_previous;
            }
        }
    }
}
