#pragma once
#include <list>
#include <SFML\Graphics.hpp>
#include "Pathing_edge.h"



class Pathing_node;
typedef std::list<Pathing_edge*> EdgeList;


class Pathing_node
{
public:
    Pathing_node();
    ~Pathing_node();

    //the node that this node can be most efficiently reached from
    Pathing_node* m_previous;


    
    //render me function
    void draw();
    //links to all nearby valid nodes
    void linkToNodes();


    sf::Vector2f getPos();
    void setPos(sf::Vector2f position);
    void setPos(float x, float y);

    float Gscore;
    float Hscore;
    float Fscore;
    bool isWalkable;
    EdgeList connections;

private: 
    sf::Vector2f m_position;
    sf::CircleShape circle;
   
    //all nodes this node is connected to
    

};

