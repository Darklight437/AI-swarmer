#include "Pathing_Walker.h"
#include "SFML\Window\Mouse.hpp"
#include <algorithm>
#include <list>
#include <cmath>


Pathing_Walker::Pathing_Walker()
{
}


Pathing_Walker::~Pathing_Walker()
{
}




Pathing_node* Pathing_Walker::Astar(NodeList allNodes, Pathing_node* startNode, Pathing_node* targetNode)
{
    NodeList closedSet;
    NodeList openSet;
    

    //attempting to path to the node you are already at
    if (startNode == targetNode)
    {

        //break and just tell it to move to where it is already
        return startNode;
    }

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


        openSet.remove(current);
        closedSet.push_front(current);


        //find all the neighbours of this current node
        //and add them to the potential route
        for (auto neighbour: current->connections)
        {
            
            //check if the neighbour is in the closedSet
            if (std::find(closedSet.begin(),closedSet.end(),neighbour->otherNode(current)) != closedSet.end())
            {
                //do nothing to node1
            }
            //node one is not in the closedSet
            //throw it in the list of potential paths
            else
            {
                openSet.push_back(neighbour->Node1);
                
            }

            
            //get the gscore based off distance from start to a neighbouring node
            //aaah
            float tentativeGscore = current->Gscore + distBetween(current, neighbour->otherNode(current));
            //if the distance is higher than 
            if (tentativeGscore >= neighbour->otherNode(current)->Gscore)
            {


                
            }

        }
            
           


        }

        
       
            




    //shh no problem here comrade
      
        return Pathing_node;
    }
}


Pathing_node* Pathing_Walker::buildPath(Pathing_node * start, Pathing_node * end)
{
    Pathing_node* current = start;

    //just link all the nodes and return the first node in the list as a pointer
    //so this should step back through the pointers and confirm that they all link and if the
    
    while (current->m_previous != nullptr)
    {

    }
    //follow the pointers back through the nodes to find the strat from the end and then return this in some form
    //make sure everything is linked before returning this
    return current;
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


//returns the distance between two nodes;
float Pathing_Walker::distBetween(Pathing_node * currNode, Pathing_node * targetNode)
{
    float tempX = 0;
    float tempY = 0;
    float squaredDist = 0;
    tempX = currNode->getPos().x;
    tempX *= tempX;
    tempY = currNode->getPos().y;
    tempY *= tempY;
    squaredDist = tempX + tempY;
    squaredDist = sqrtf(squaredDist);
    return squaredDist;
}

void Pathing_Walker::generateNodes()
{
    int nodePosX = 0;
    int nodePosY = 0;
    for (nodePosX = 0; nodePosX < 1000; nodePosX += 100 )
    {
        for (nodePosY = 0; nodePosY < 1000; nodePosY += 100 )
        {
            //make a node
            Pathing_node* newNode = new Pathing_node;
            newNode->setPos(nodePosX, nodePosY);
            allNodes.push_back(newNode);
            

        }//end for
        
    }//out of all loops

    // go through each node and find its "neighbours" and create an edge between them, this should also
    //for every node in all node list
    for (auto &node : allNodes)
    {
        
        linkNode(node);
    }


    //return a list of 100 nodes connected to each other including diagonals
    
}



void Pathing_Walker::generateSingleNode()
{
    //click and create one node at mouse position

}



void Pathing_Walker::movenodes()
{
    std::list<Pathing_node*>::iterator iter;
    float searchRadiusSquared = 10000;
        for (iter = allNodes.begin(); iter != allNodes.end(); iter++)
        {
            float VectToTarget = (((*iter)->getPos().x - sf::Mouse::getPosition().x) + ((*iter)->getPos().y - sf::Mouse::getPosition().y));
            if ( VectToTarget < searchRadiusSquared)
            {
                //child the node to the mouse for movement
            }
        }
    
}



void Pathing_Walker::drawNodes(sf::RenderWindow* render)
{

    //sf::CircleShape circle(20);

    //render->draw(circle);

    for (auto &node : allNodes)
    {

        for (auto &edge : allEdges)
        {
            edge->drawn = false;
        }
    }


    
    for (auto &node : allNodes) 
    {
        render->draw(node->circle);

        
         for (auto &edge : allEdges)
        {
            if (!edge->drawn)
            {
                render->draw(*(edge->getEdge()));
                edge->drawn = true;
            }
            
        }
    }
}



//TODO step through here and figure out whats not working
void Pathing_Walker::linkNode( Pathing_node* currentNode)
{
    //gets called in a loop so it shoufl only link up one node to its neighbors


        std::list<Pathing_node*> nearbyNodes;
       //check each node to see if it is the current iand if not
        //look at its distance from the master node        
        for (auto &node : allNodes)
        {
            if ((node) != currentNode)
            {

                sf::Vector2f dispVect = currentNode->getPos() - (node)->getPos();

                float squaredDistanceFromMe = (dispVect.x * dispVect.x) + (dispVect.y * dispVect.y);
                //valid range nodes
                if (squaredDistanceFromMe <= squaredRadius)
                {
                    nearbyNodes.push_back(node);
                }


            }
        }// /for
        //confirmed working, is collating nodes in the nearbynodes list
        

        for (auto &nearbyNode : nearbyNodes)
        {
            bool connected = false;
            //if neither node has a connection assume there are no edges associated
            if (currentNode->connections.empty() && nearbyNode->connections.empty())
            {
                Pathing_edge* newEdge = new Pathing_edge;
                newEdge->Node1 = currentNode;
                newEdge->Node2 = (nearbyNode);
                currentNode->connections.push_back(newEdge);
                nearbyNode->connections.push_back(newEdge);
                allEdges.push_back(newEdge);
                connected = true;
            }
            //check if the nodes are already connected
            else
            {
                
                for (auto &edgecheck : currentNode->connections)
                {
                    if (edgecheck->Node1 == nearbyNode || edgecheck->Node2 == nearbyNode)
                    {
                        connected = true;
                        break;
                    }
                } // for
            }
            

            if (connected == false)
            {
                Pathing_edge* newEdge = new Pathing_edge;
                newEdge->Node1 = currentNode;
                newEdge->Node2 = nearbyNode;
                currentNode->connections.push_back(newEdge);
                allEdges.push_back(newEdge);
            }
            
                
            



        } // /for nodes
}


