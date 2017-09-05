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

   
    
    

    
    //render me function
    
    //links to all nearby valid nodes
    
    sf::CircleShape circle;

    sf::Vector2f getPos();
    void setPos(sf::Vector2f position);
    void setPos(float x, float y);


    //pathfinding scores 
    float Gscore = 0;
    float Hscore = 0;
    float Fscore = 0;
    bool isWalkable = true;
    //all the edges this node has
    EdgeList connections;

private: 

    sf::Vector2f m_position;

   

    

};

