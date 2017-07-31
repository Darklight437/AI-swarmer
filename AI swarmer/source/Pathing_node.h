#pragma once
#include <list>
#include <SFML\Graphics.hpp>
#include "Pathing_edge.h"



class Pathing_node;
typedef std::list<Pathing_node*> NodeList;


class Pathing_node
{
public:
    Pathing_node();
    ~Pathing_node();
    //the node that this node can be most efficiently reached from
    Pathing_node* m_previous;


    
    //render me function
    void draw();


    sf::CircleShape circle;
    sf::Vector2f m_position;
    float Gscore;
    float Hscore;
    float Fscore;
    bool isWalkable;
    //all nodes this node is connected to
    NodeList connections;

};

