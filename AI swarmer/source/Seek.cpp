#include "Seek.h"



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
    //get the vector to the target, subtract myPos
    //normalise 

    return steeringForce;
}
