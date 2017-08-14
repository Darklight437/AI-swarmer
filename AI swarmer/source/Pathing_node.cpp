#include "Pathing_node.h"
#include <algorithm>


Pathing_node::Pathing_node()
{
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
}

void Pathing_node::setPos(float x, float y)
{
    m_position.x = x;
    m_position.y = y;
}




