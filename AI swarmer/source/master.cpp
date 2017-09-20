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
    m_sprite.setOrigin(sf::Vector2f(m_sprite.getGlobalBounds().width / 2, m_sprite.getGlobalBounds().height / 2));
    myAgent->setTopSpeed(100);
}

master::master()
{
   
   loadSprite();


   
}


master::~master()
{

}
//seeks a dingle point

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
