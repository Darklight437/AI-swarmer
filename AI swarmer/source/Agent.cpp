#include "Agent.h"



Agent::Agent()
{
    
    
}


Agent::~Agent()
{

}

sf::Vector2f Agent::getSteeringForce()
{
   
    //get each behavior just seek for now
    //add all their steeringforce values together to get this frame's force
        
    ((Seek*)seekBehavior)->calculateForce()

    
    
    return steeringForce;
}
