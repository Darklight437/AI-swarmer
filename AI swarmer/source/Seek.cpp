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


    return steeringForce;
}
