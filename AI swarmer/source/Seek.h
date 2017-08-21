#pragma once
#include "Behavior.h"
#include<SFML\Graphics\Transformable.hpp>

class Seek :
    public Behavior
{
public:
    Seek();
    ~Seek();
    Seek(sf::Vector2f myPosition);


private:
    sf::Vector2f myPos;
    sf::Vector2f m_targetPos;
    sf::Vector2f steeringForce;


};

