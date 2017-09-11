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
    if (seek)
    {
        steeringForce = ((Seek*)seekBehavior)->calculateForce(myPosition, targetPosition);

    }
    if (flock)
    {
        steeringForce = ((Flock*)FlockBehavior)->calculateForce(myPosition, targetPosition);
    }
   
    
    
    return steeringForce;
}
