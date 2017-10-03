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


void Agent::removeNeighbour(Gameobject * neighbour, NeighbourTyp T)
{
    
    if (T == NeighbourTyp::COHERE)
    {
         auto it = (std::find(Neighbours.cohereNeighbours.begin(), Neighbours.cohereNeighbours.end(), neighbour));
         if (it != Neighbours.cohereNeighbours.end())
         {
             Neighbours.cohereNeighbours.remove(*it);
         }
        
    }
    if (T == NeighbourTyp::ALIGN)
    {
        auto it = (std::find(Neighbours.alignNeighbours.begin(), Neighbours.alignNeighbours.end(), neighbour));
        if (it != Neighbours.cohereNeighbours.end())
        {
            Neighbours.cohereNeighbours.remove(*it);
        }
    }
    if (T == NeighbourTyp::SEP)
    {
        auto it = (std::find(Neighbours.separateNeighbours.begin(), Neighbours.separateNeighbours.end(), neighbour));
        if (it != Neighbours.cohereNeighbours.end())
        {
            Neighbours.cohereNeighbours.remove(*it);
        }
    }
}



void Agent::setTopSpeed(float speed)
{
    movementSpeed = speed;
}


