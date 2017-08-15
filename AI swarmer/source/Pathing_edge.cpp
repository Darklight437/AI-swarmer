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

sf::RectangleShape * Pathing_edge::getEdge()
{
    calculateRect();
    return &m_line;
}

void Pathing_edge::calculateRect()
{
    sf::Vector2f centerpoint = (Node1->getPos() + Node2->getPos()) / 2.0f;
    float dist = magnitude(Node1->getPos() - Node2->getPos());
    float angle = angleOfVect(Node1->getPos() - Node2->getPos());

    m_line.setPosition(centerpoint);
    m_line.setSize(sf::Vector2f(dist, 2));
    m_line.setRotation(angle);
    m_line.setOrigin(m_line.getGlobalBounds().width / 2, m_line.getGlobalBounds().height / 2);


}




