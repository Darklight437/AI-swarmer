#include "Agent.h"



Agent::Agent()
{
    behaviors.push_back(Behavior* seek = new Seek)
}


Agent::~Agent()
{
}

sf::Vector2f Agent::getSteeringForce()
{
    if (behaviors.empty() == false)
    {
        for (auto &behavior :behaviors)
        {
            steeringForce += behavior->Force;
        }
        return steeringForce;
    }

    
    steeringForce.x = 0;
    steeringForce.y = 0;
    return steeringForce;
}
