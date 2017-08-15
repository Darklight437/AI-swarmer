#include "Pathing_node.h"
#include <algorithm>


Pathing_node::Pathing_node()
{
    m_position.x = 0;
    m_position.y = 0;
    circle.setRadius(10);
    circle.setOutlineThickness(3);
    circle.setFillColor(sf::Color(0, 0, 0));
    circle.setOutlineColor(sf::Color(255, 255, 255));
    m_previous = nullptr;
}


Pathing_node::~Pathing_node()
{
}


sf::Vector2f Pathing_node::getPos()
{
    return m_position;
}

void Pathing_node::setPos(sf::Vector2f position)
{
    m_position = position;
    circle.setPosition(m_position);
}

void Pathing_node::setPos(float x, float y)
{
    m_position.x = x;
    m_position.y = y;
    circle.setPosition(m_position);
}




