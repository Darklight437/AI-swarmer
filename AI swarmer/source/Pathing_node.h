#pragma once
#include <list>
#include <SFML\Graphics.hpp>
#include "Pathing_edge.h"
#include <SFML\Graphics\Drawable.hpp>


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
    
    //links to all nearby valid nodes
    


    sf::Vector2f getPos();
    void setPos(sf::Vector2f position);
    void setPos(float x, float y);


    //pathfinding scores 
    float Gscore;
    float Hscore;
    float Fscore;
    bool isWalkable;
    //all the edges this node has
    EdgeList connections;

private: 

    sf::Vector2f m_position;
    sf::CircleShape circle;
   

    

};

