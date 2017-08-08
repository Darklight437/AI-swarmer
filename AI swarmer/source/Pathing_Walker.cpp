#include "Pathing_Walker.h"



Pathing_Walker::Pathing_Walker()
{
}


Pathing_Walker::~Pathing_Walker()
{
}




void Pathing_Walker::Astar(NodeList allNodes, Pathing_node* startNode, Pathing_node* targetNode)
{
    NodeList closedSet;
    NodeList openSet;
    
    startNode->m_previous = nullptr;
    startNode->Gscore = 0;


    openSet.push_front(startNode);

    while (!openSet.empty())
    {
        Pathing_node* current;
        //find the lowest fscore node
        current = bestScore(openSet);
        //if you find the end
        if (current == targetNode)
        {
            buildPath(current, startNode);
            //probably break out here or something
        }
        

        //get all connected nodes
       
     //   NodeList connectedNodes = current->connections;
        
        openSet.remove(current);
      

        closedSet.push_front(current);
       
        if (startNode == targetNode)
        {   
            //break and explode
            return;
        }

    }
}

void Pathing_Walker::buildPath(Pathing_node * start, Pathing_node * end)
{
    //follow the pointers back through the nodes to find the strat from the end and then return this in some form
    return;//no clue
}
//return the lowest Fscore 
Pathing_node * Pathing_Walker::bestScore(NodeList openList)
{
    Pathing_node* lowest = openList.front();
    Pathing_node* current = openList.front();

    for (std::list<Pathing_node*>::iterator it = openList.begin(); it != openList.end(); ++it)
    {

        current = *it;
        if (lowest->Fscore > current->Fscore)
        {
            lowest = current;
        }
        else if (lowest->Fscore == current->Fscore)
        {
            if (lowest->Hscore > current->Hscore)
            {
                lowest = current;
            }            
        }
    }

    return lowest;
}

std::list<Pathing_node*> Pathing_Walker::generateNodes()
{
    NodeList nodes;
    for (int i = 0; i < 100; i++)
    {
        //make a node
        Pathing_node* fooptr = new Pathing_node;
        nodes.push_back(fooptr);



        //figure out how to find if there are other nodes nearby
        //get an add edges function
        
    }


    //return a list of 100 nodes connected to each other including diagonals
    return nodes;
}

void Pathing_Walker::addEdges(Pathing_node*)
{

    
}


