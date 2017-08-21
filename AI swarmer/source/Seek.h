#pragma once
#include "Behavior.h"
#include<SFML\Graphics\Transformable.hpp>
#include 
class Seek :
    public Behavior
{
public:
    Seek();
    ~Seek();



private:
    sf::Vector2f myPos;
    sf::Vector2f m_targetPos;
    sf::Vector2f steeringForce;


};

