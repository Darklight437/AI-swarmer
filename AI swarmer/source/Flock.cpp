#include "Flock.h"



Flock::Flock()
{
}


Flock::~Flock()
{
}

sf::Vector2f Flock::calculateForce(sf::Vector2f myPosition, std::list<Swarmer*>neighbours)
{
    sf::Vector2f steeringF;
    sf::Vector2f separationF;
    sf::Vector2f alignF;
    sf::Vector2f cohereF;
    for each (Swarmer* neighbour in neighbours)
    {
       separationF = separation(myPosition, neighbour->m_sprite.getPosition());
       alignF = align(neighbour->);
       cohereF = cohere(myPosition, neighbour->m_sprite.getPosition());
    }




    return steeringF;
}

sf::Vector2f Flock::separation(sf::Vector2f myPosition, sf::Vector2f neighbour)
{
    sf::Vector2f separationForce;
    separationForce += myPosition - neighbour;

    return separationForce;
   
}

sf::Vector2f Flock::align(sf::Vector2f myPosition, sf::Vector2f neighborV)
{
    sf::Vector2f alignforce;

    alignforce = 



    return sf::Vector2f();
}
