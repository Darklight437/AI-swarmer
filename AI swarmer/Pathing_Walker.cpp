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

    while (true)
    {

        std::sort(openSet.m_nodeptrs.front(), openSet.m_nodeptrs.back(), sortNodePtrs());
        
        openSet.m_nodeptrs.push_front(startNode);

        if (startNode == endNode)
        {   
            return;
        }

    }
}


