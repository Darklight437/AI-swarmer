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
    
    steeringForce = myPos - m_targetPos;
    
    steeringForce = normalise(steeringForce);
    steeringForce * seekspeed;


    return steeringForce;
}
