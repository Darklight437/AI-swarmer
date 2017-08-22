#include "Seek.h"
#include "Vmath.h"


Seek::Seek()
{
}


Seek::~Seek()
{
}

//Seek::Find(sf::Vector2f myPosition)
//{
//    myPos = myPosition;
//}

sf::Vector2f Seek::calculateForce(sf::Vector2f myPosition, sf::Vector2f targetPosition)
{
    
    steeringForce = myPosition - targetPosition;
    
    steeringForce = normalise(steeringForce);
    steeringForce * seekspeed;


    return steeringForce;
}
