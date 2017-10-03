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

    //sf::Vector2f flockForce;

    //flockForce = 
    return ((Flock*)FlockBehavior)->calculateForce(thisObject, Neighbours, targetPos);
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


void Agent::removeNeighbour(Gameobject * neighbour, NeighbourTyp T)
{
    //auto it is breaking
    //
    if (T == NeighbourTyp::COHERE)
    {
        Neighbours.cohereNeighbours.remove(neighbour);
    }
    if (T == NeighbourTyp::ALIGN)
    {  
        Neighbours.alignNeighbours.remove(neighbour);
    }
    if (T == NeighbourTyp::SEP)
    {
        Neighbours.separateNeighbours.remove(neighbour);
    }
}



void Agent::setTopSpeed(float speed)
{
    movementSpeed = speed;
}

void Agent::clearNeighbours()
{
    Neighbours.alignNeighbours.clear();
    Neighbours.cohereNeighbours.clear();
    Neighbours.separateNeighbours.clear();
}


