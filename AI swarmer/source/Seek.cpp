#include "Seek.h"
#include "Vmath.h"


Seek::Seek()
{
}


Seek::~Seek()
{
}

Seek::Seek(sf::Vector2f myPosition)
{
    myPos = myPosition;
}

sf::Vector2f Seek::calculateForce()
{
    float targetMagnitude = 0;
    steeringForce = myPos - m_targetPos;
    targetMagnitude = magnitude(steeringForce);
    
    //get the vector to the target, subtract myPos
    //normalise 

    return steeringForce;
}
