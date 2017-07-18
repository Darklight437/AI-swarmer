#include "Pathing_Walker.h"



Pathing_Walker::Pathing_Walker()
{
}


Pathing_Walker::~Pathing_Walker()
{
}

void Pathing_Walker::Astar(Pathing_node* startNode, Pathing_node* endNode)
{
    Node_holder closedSet;
    Node_holder openSet;

    startNode->m_parent = nullptr;

    while (true)
    {

    
    
        openSet.m_nodeptrs.push_front(startNode);

        if (startNode == endNode)
        {   
            return;
        }

    }
}
