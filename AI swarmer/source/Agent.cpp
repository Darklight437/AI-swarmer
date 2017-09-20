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

    flockForce = ((Flock*)FlockBehavior)->calculateForce(thisObject, Neighbours, targetPos);
    return flockForce;
}

void Agent::addAlign(Gameobject * neighbour)
{
    Neighbours.alignNeighbours.push_back(neighbour);
}

void Agent::addCohere(Gameobject * neighbour)
{
    Neighbours.cohereNeighbours.push_back(neighbour);
}

void Agent::addSeparate(Gameobject * neighbour)
{
    Neighbours.separateNeighbours.push_back(neighbour);
}



void Agent::setTopSpeed(float speed)
{
    movementSpeed = speed;
}


