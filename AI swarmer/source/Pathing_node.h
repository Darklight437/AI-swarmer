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

    sf::CircleShape circle;
    sf::Vector2f m_position;

    float Gscore;
    float Hscore;
    float Fscore;
    bool isWalkable;

private: 


    //square root of the radius to check for nodes
    float sqrtSearchRad;
    void radiusForCheck(std::list <Pathing_node*> nodesToSearch);
    //all nodes this node is connected to
    EdgeList connections;

};

