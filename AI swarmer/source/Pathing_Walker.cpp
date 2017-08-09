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

void Pathing_Walker::generateNodes()
{
   
    for (int i = 0; i < 100; i++)
    {
        //make a node
        Pathing_node* newNode = new Pathing_node;
        allNodes.push_back(newNode);
    }

    // go through each node and find its "neighbours" and create an edge between them, this should also
    NodeList::iterator it;
    for (it = allNodes.begin(); it != allNodes.end(); it++)
    {
        linkNode(allNodes, (*it));
    }


    //return a list of 100 nodes connected to each other including diagonals
    
}



void Pathing_Walker::linkNode(std::list<Pathing_node*> nodesToSearch, Pathing_node* currentNode)
{
    

        std::list<Pathing_node*> LinkedNodes;
        std::list<Pathing_node*>::iterator iter;
        for (iter = nodesToSearch.begin(); iter != nodesToSearch.end(); iter++)
        {
            if ((*iter) != currentNode)
            {

                sf::Vector2f dispVect = currentNode->getPos() - (*iter)->getPos();

                float squaredMagnitude = (dispVect.x * dispVect.x) + (dispVect.y * dispVect.y);
                //valid range nodes
                if (squaredMagnitude < squaredRadius)
                {
                    LinkedNodes.push_back(currentNode);
                }


            }
        }// /for
        EdgeList::iterator edgeSearch;

        for (iter = LinkedNodes.begin(); iter != LinkedNodes.end(); iter++)
        {
            for (edgeSearch = currentNode->connections.begin(); edgeSearch != currentNode->connections.end(); edgeSearch++)
            {
                if ((*edgeSearch)->Node1 != currentNode && (*edgeSearch)->Node2 != currentNode);
                {
                    Pathing_edge* newEdge = new Pathing_edge;
                    newEdge->Node1 = currentNode;
                    newEdge->Node2 = (*iter);
                    currentNode->connections.push_back(newEdge);
                    allEdges.push_back(newEdge);
                    //work out how to store these
                }

            }

        } // /for 
}


