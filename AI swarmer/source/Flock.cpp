#include "Flock.h"
#include "Gameobject.h"
#include "Vmath.h"
#include "Agent.h"

Flock::Flock()
{
}


Flock::~Flock()
{
}

sf::Vector2f Flock::calculateForce(sf::Vector2f myPosition, sf::Vector2f targetPosition, float speed)
{
    //dunno about needing this function, i'd wanted to overload it but this is "cleaner"
    return sf::Vector2f();
}

sf::Vector2f Flock::calculateForce(Gameobject* thisObject, Agent::FlockingNeighbours neighbourhood, sf::Vector2f targetPos)
{
    sf::Vector2f steeringF;
    sf::Vector2f separationF;
    sf::Vector2f alignF;
    sf::Vector2f cohereF;
    //#######################################################################################################
    //#######################################################################################################
    //seek stuff

    steeringF = targetPos - thisObject->m_sprite.getPosition();
    steeringF = normalise(steeringF);
    steeringF *= 10.0f;
    
    
   

    //#######################################################################################################
    //#######################################################################################################
    
    for each (Gameobject* neighbour in neighbourhood.alignNeighbours)
    {
      
       alignF += align(neighbour->getVelocity());
       
    }
    for each (Gameobject* neighbour in neighbourhood.cohereNeighbours)
    {

    }
    for each (Gameobject* neighbour in neighbourhood.separateNeighbours)
    {

    }

    //3 of these
    
    float separationSize = neighbourhood.separateNeighbours.size();
    float alignSize = neighbourhood.alignNeighbours.size();
    float cohereSize= neighbourhood.cohereNeighbours.size();

    separationF /= separationSize;
    alignF /= alignSize;
    cohereF /= cohereSize;


    steeringF += ((separationF - thisObject->getVelocity()) * separateWeight)
              + ((alignF - thisObject->getVelocity()) * alignWeight)
              + ((cohereF - thisObject->getVelocity()) * cohesionWeight);

    steeringF *= 10.0f;
    return steeringF;
}

sf::Vector2f Flock::separation(sf::Vector2f myPosition, sf::Vector2f neighbour)
{
    sf::Vector2f separationForce;
    separationForce = myPosition - neighbour;

    return separationForce;
   
}

sf::Vector2f Flock::align(sf::Vector2f neighborV)
{
    sf::Vector2f alignforce;

    alignforce = neighborV;



    return alignforce;
}

sf::Vector2f Flock::cohere(sf::Vector2f myPosition, sf::Vector2f neighbourPos)
{
    sf::Vector2f cohesionForce = neighbourPos - myPosition;
    return cohesionForce;
}

std::list<Gameobject*> Flock::getNeighbours(Gameobject* thisSwarmer)
{

    return std::list<Gameobject*>();
}
