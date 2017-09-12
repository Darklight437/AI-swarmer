#include "Flock.h"
#include "Gameobject.h"


Flock::Flock()
{
}


Flock::~Flock()
{
}

sf::Vector2f Flock::calculateForce(sf::Vector2f myPosition, sf::Vector2f targetPosition)
{
    //dunno about needing this function, i'd wanted to overload it but this is "cleaner"
    return sf::Vector2f();
}

sf::Vector2f Flock::calculateForce(sf::Vector2f myPosition, std::list<Gameobject*>neighbours)
{
    sf::Vector2f steeringF;
    sf::Vector2f separationF;
    sf::Vector2f alignF;
    sf::Vector2f cohereF;

    for each (Gameobject* neighbour in neighbours)
    {
       separationF += separation(myPosition, neighbour->m_sprite.getPosition())  ;
       alignF += align(neighbour->getVelocity());
       cohereF += cohere(myPosition, neighbour->m_sprite.getPosition());
    }
    float sizeOfList = neighbours.size();

    separationF /= sizeOfList;
    alignF /= sizeOfList;
    cohereF /= sizeOfList;

    //minus velocity somehow
    //nah just do that in a layer above
    //hopefully

    steeringF = (separationF * separateWeight) + (alignF * alignWeight) + (cohereF * cohesionWeight);

    return steeringF;
}

sf::Vector2f Flock::separation(sf::Vector2f myPosition, sf::Vector2f neighbour)
{
    sf::Vector2f separationForce;
    separationForce += myPosition - neighbour;

    return separationForce;
   
}

sf::Vector2f Flock::align(sf::Vector2f neighborV)
{
    sf::Vector2f alignforce;

    alignforce = neighborV;



    return alignforce;
}

sf::Vector2f Flock::cohere(sf::Vector2f myPosition, sf::Vector2f neighbourPos)
{
    sf::Vector2f cohesionForce = neighbourPos - myPosition;
    return cohesionForce;
}
