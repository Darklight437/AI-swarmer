#include "Gameobject.h"
#include <Windows.h>
#include "deltaClock.h"
#include "Vmath.h"
#include <cmath>
#include "Agent.h"

Gameobject::Gameobject()
{
    myAgent = new Agent;
}

Gameobject::Gameobject(std::string spriteFileName)
{
    if (!m_texture.loadFromFile(spriteFileName))
    {
        //freak out somehow maybe an exception
    }
    m_texture.setSmooth(false);
    m_sprite.setTexture(m_texture);
    
}


Gameobject::~Gameobject()
{
    delete myAgent;
}


 std::string Gameobject::getExecutableFolder()
{
    char buffer[MAX_PATH];
    GetModuleFileName(NULL, buffer, MAX_PATH);
    char *pos;
    if (pos = strrchr(buffer, '\\'))
    {
        *pos = 0;
    }

    return buffer;
}

 void Gameobject::setPosition(sf::Vector2f position)
 {
     m_sprite.setPosition(position);
 }

 void Gameobject::setPosition(float x, float y)
 {
     m_sprite.setPosition(x, y);
 }

 void Gameobject::setRotation(float r)
 {
     m_sprite.setRotation(r);
 }

 void Gameobject::steer(sf::Vector2f target)
 {
     sf::Vector2f steering;
     //returns a vector2f that is the total motion force on the object
     steering = myAgent->getSteeringForce(m_sprite.getPosition(), target);
     //how to actually move towards this position pl0x
     m_acceleration = steering;

     setRotation(angleOfVect(steering));

 }

 void Gameobject::flock(sf::Vector2f leader)
 {
     sf::Vector2f steering;


     
     steering = myAgent->getFlockForce(this, leader);

     //then search your locality & add all available nearby swarmers to the list

     m_acceleration = steering;
     setRotation(angleOfVect(steering));
 }

 sf::Vector2f Gameobject::getVelocity()
 {
     return m_velocity;
 }

 void Gameobject::getNeighbours(std::list<Gameobject*> swarmerList)
 {

     for each (Gameobject* Swarmer in swarmerList)
     {
         if (find2DistFromMe(Swarmer->m_sprite.getPosition()) < 360000)
         {
             myAgent->addAlign(Swarmer);
         }
         if (find2DistFromMe(Swarmer->m_sprite.getPosition()) < 90000)
         {

         }
         

     }

 }

 


 void Gameobject::update()
 {
    //all movement happens HERE
    //deltatime should live here
     

     m_velocity = m_acceleration * (float)CLOCK->getelapsedTime();


     m_sprite.move(m_velocity);

     
 }

 float Gameobject::findDistFromMe(sf::Vector2f target)
 {
    sf::Vector2f targetVect;
    targetVect = m_sprite.getPosition() - target;

    float newX = targetVect.x * targetVect.x;
    float newY = targetVect.y * targetVect.y;

    float distance = sqrt(newX + newY);
    return distance;
 }

 float Gameobject::find2DistFromMe(sf::Vector2f target)
 {
     sf::Vector2f targetVect;
     targetVect = m_sprite.getPosition() - target;

     float newX = targetVect.x * targetVect.x;
     float newY = targetVect.y * targetVect.y;

     float distance = newX + newY;
     return distance;
 }

