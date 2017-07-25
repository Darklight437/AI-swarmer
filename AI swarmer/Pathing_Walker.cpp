#include "Pathing_Walker.h"



Pathing_Walker::Pathing_Walker()
{
}


Pathing_Walker::~Pathing_Walker()
{
}




void Pathing_Walker::Astar(Pathing_node* startNode, Pathing_node* endNode)
{
    std::list<Pathing_node*> closedSet;
    std::list<Pathing_node*> openSet;

    startNode->m_previous = nullptr;
    startNode->Gscore = 0;


    openSet.push_front(startNode);

    while (!openSet.empty())
    {
        Pathing_node* current;
        //find the lowest fscore node
        //current = //write a loop to find the lowest
        if (current == endNode)
        {
            buildPath(current, startNode);
            //probably break out here or something
        }
        
        //openSet.m_nodeptrs.remove(current)
        closedSet.push_front(current);

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
//return the lowest Fscore 
{


    {
        if (lowest->Fscore > current->Fscore)
        {
            lowest = current;
        }

    }
    return nullptr;
}


