#include "Agent.h"



Agent::Agent()
{
    
    
}


Agent::~Agent()
{
    delete seekBehavior;
    delete FlockBehavior;
}

sf::Vector2f Agent::getSteeringForce(sf::Vector2f myPosition, sf::Vector2f targetPosition)
{
    sf::Vector2f steeringForce;
    //get each behavior just seek for now
    //add all their steeringforce values together to get this frame's force

    Seek * DS = ((Seek*)seekBehavior);
    DS->calculateForce(myPosition, targetPosition,movementSpeed);
    //do an if test on this
        steeringForce = ((Seek*)seekBehavior)->calculateForce(myPosition, targetPosition,movementSpeed);

    
    return steeringForce;
}

sf::Vector2f Agent::getFlockForce(Gameobject* thisObject, sf::Vector2f targetPos)
{

    sf::Vector2f flockForce;

    flockForce = ((Flock*)FlockBehavior)->calculateForce(thisObject, flockingNeighbours);
    return flockForce;
}

void Agent::addNeighbour(Gameobject * thisSwarmer)
{
    if (std::find(flockingNeighbours.begin(), flockingNeighbours.end(), thisSwarmer) == flockingNeighbours.end())
    {
        flockingNeighbours.push_back(thisSwarmer);
    }
}

void Agent::removeNeighbour(Gameobject * thisSwarmer)
{
   
    if (std::find(flockingNeighbours.begin(), flockingNeighbours.end(), thisSwarmer) != flockingNeighbours.end())
    {
        flockingNeighbours.remove(thisSwarmer);
    }

}

void Agent::setTopSpeed(float speed)
{
    movementSpeed = speed;
}


