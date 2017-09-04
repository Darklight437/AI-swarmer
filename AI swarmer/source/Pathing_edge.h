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
    
    bool drawn = false;
    Pathing_node* Node1;
    Pathing_node* Node2;
    Pathing_node* otherNode(Pathing_node* thisNode);
    //returns the sf::shape as a pointer that represents the edge
    sf::RectangleShape* getEdge();

private:
    sf::RectangleShape m_line;
    void calculateRect();
    
    
};

