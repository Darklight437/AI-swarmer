#include "Pathing_Walker.h"



Pathing_Walker::Pathing_Walker()
{
}


Pathing_Walker::~Pathing_Walker()
{
}

struct sortNodePtrs
{
    inline bool operator() (const Pathing_node& node1, const Pathing_node& node2)
    {
        return (node1.Fscore < node2.Fscore);
    }
};




void Pathing_Walker::Astar(Pathing_node* startNode, Pathing_node* endNode)
{
    Node_holder closedSet;
    Node_holder openSet;

    startNode->m_parent = nullptr;
    startNode->Gscore = 0;


    openSet.m_nodeptrs.push_front(startNode);

    while (!openSet.m_nodeptrs.empty())
    {
        Pathing_node* current;

        if (current == endNode)
        {
            buildPath(current, startNode);
        }
        
        

        if (startNode == endNode)
        {   
            return;
        }

    }
}


