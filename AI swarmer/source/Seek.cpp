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

sf::Vector2f Seek::calculateForce(sf::Vector2f myPosition, sf::Vector2f targetPosition, float speed)
{
    
    steeringForce = targetPosition - myPosition;
    
    steeringForce = normalise(steeringForce);
    steeringForce *= speed;


    return steeringForce;
}
