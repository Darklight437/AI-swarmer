#pragma once
#include "SFML\Graphics.hpp"
class Behavior
{
public:
    Behavior();
    virtual ~Behavior();

    sf::Vector2f m_Force;
    sf::Vector2f m_target;
protected:
    virtual sf::Vector2f calculateForce(sf::Vector2f myPosition, sf::Vector2f targetPosition, float speed) = 0;



};

