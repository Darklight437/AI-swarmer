#include "Pathing_Walker.h"



Pathing_Walker::Pathing_Walker()
{
}


Pathing_Walker::~Pathing_Walker()
{
}
//like this but not borked??
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
        current = openSet.m_nodeptrs.front();//incorrect should get the lowest Fscore node
        if (current == endNode)
        {
            buildPath(current, startNode);
            //probably break out here or something
        }
        
        //openSet.m_nodeptrs.remove(current)
        closedSet.m_nodeptrs.push_front(current);

        for each (Pathing_edge* curredge in current->connections)
        {
            if (curredge->)
        }

        if (startNode == endNode)
        {   
            return;
        }

    }
}

void Pathing_Walker::buildPath(Pathing_node * start, Pathing_node * end)
{
    //lol idk
    return;//no clue
}


