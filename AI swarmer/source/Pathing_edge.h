#pragma once
#include <SFML\Graphics.hpp>
//forward dec
class Pathing_node;

class Pathing_edge
{
public:
    struct edgeLinks;

    Pathing_edge();
    ~Pathing_edge();
    float getCost();
    Pathing_node* Node1;
    Pathing_node* Node2;
    float m_cost;
    //returns the sf::shape as a pointer that represents the edge
    sf::RectangleShape* getEdge();

private:
    sf::RectangleShape m_line;
    void calculateRect();


};

