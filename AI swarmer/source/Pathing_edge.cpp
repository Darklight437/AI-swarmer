#include "Pathing_edge.h"
#include "Pathing_node.h"
#include "Vmath.h"

Pathing_edge::Pathing_edge()
{
    m_line.setFillColor(sf::Color::Blue);

}


Pathing_edge::~Pathing_edge()
{
}

float Pathing_edge::getCost()
{
    return m_cost;
}

void Pathing_edge::calculateRect()
{
    sf::Vector2f centerpoint = (Node1->getPos() + Node2->getPos()) / 2.0f;
    float dist = magnitude(Node1->getPos() - Node2->getPos());


}




