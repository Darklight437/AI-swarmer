#include "Pathing_Walker.h"
#include "SFML\Window\Mouse.hpp"
#include <algorithm>
#include <list>
#include <cmath>
#include "Vmath.h"


Pathing_Walker::Pathing_Walker()
{
}


Pathing_Walker::~Pathing_Walker()
{
}




NodeList Pathing_Walker::Astar(NodeList allNodes, Pathing_node* startNode, Pathing_node* targetNode)
{
    NodeList closedSet;
    NodeList openSet;
    NodeList path ;
    

    //attempting to path to the node you are already at
    if (startNode == targetNode)
    {

        //break and just tell it to move to where it is already
        path.push_front(startNode);
        return path;
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

            path = buildPath( startNode, targetNode);
            //this is the  "i'm done bit"
            
            return path;
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
                //ignore neighbour as already evaluated
                continue;
            }
            //if the node is a wall dont check it
            if (!current->isWalkable)
            {
                continue;
            }

            //node is not in the closedSet
            //throw it in the list of potential paths if it isn't already

            
            //if node NOT in openset
            if (std::find(openSet.begin(), openSet.end(), neighbour->otherNode(current)) != openSet.end())
            {
                float tentativeGscore = current->Gscore + distBetween(current, neighbour->otherNode(current));

                //if the cost of travelling is higher than the cost of 
                if (tentativeGscore >= neighbour->otherNode(current)->Gscore)
                {
                    //this is not a better path
                    continue;
                }

                //if you reach here this is the best path so far
                neighbour->otherNode(current)->m_previous = current;
                neighbour->otherNode(current)->Gscore = tentativeGscore;
                neighbour->otherNode(current)->Fscore = tentativeGscore + distBetween(neighbour->otherNode(current), targetNode);

            }
            else
            {
                openSet.push_back(neighbour->otherNode(current));


                float tentativeGscore = current->Gscore + distBetween(current, neighbour->otherNode(current));

                ////if the cost of travelling is higher than the cost of 
                //if (tentativeGscore >= neighbour->otherNode(current)->Gscore)
                //{
                //    //this is not a better path
                //    continue;
                //}

                //if you reach here this is the best path so far
                neighbour->otherNode(current)->m_previous = current;
                neighbour->otherNode(current)->Gscore = tentativeGscore;
                neighbour->otherNode(current)->Fscore = tentativeGscore + distBetween(neighbour->otherNode(current), targetNode);
            }
            
                
            
            
            //get the gscore based off distance from start to a neighbouring node
            


           
        }

        
    }

    
    
    




    //shh no problem here comrade
      

    }



NodeList Pathing_Walker::buildPath(Pathing_node * start, Pathing_node * end)
{
    Pathing_node* current = end;

    NodeList finalPath;
    bool startFound = false;
    while (!startFound)
    {
        if (current == start)
        {
            startFound = true;
        }

        finalPath.push_back(current);
       // current->m_previous = nullptr;
        current = current->m_previous;

    }
    if (startFound)
    {
        return finalPath;
    }
   
    
    return finalPath;
}


//return the lowest Fscore 
Pathing_node* Pathing_Walker::bestScore(NodeList openList)
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
    return (magnitude(currNode->getPos() - targetNode->getPos()));
}

float Pathing_Walker::distBetween(sf::Vector2f thisPoint, sf::Vector2f otherPoint)
{
    return magnitude(thisPoint - otherPoint);
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



Pathing_node* Pathing_Walker::clickNode(sf::Window currentWindow)
{
    std::list<Pathing_node*>::iterator iter;
    float searchRadiusSquared = 400;
    sf::Vector2f mousepos;
    mousepos.x = sf::Mouse::getPosition(currentWindow).x;
    mousepos.y = sf::Mouse::getPosition(currentWindow).y;
        for (iter = allNodes.begin(); iter != allNodes.end(); iter++)
        {
            float vectToTarget = distBetween((*iter)->circle.getPosition(), mousepos);
            if (vectToTarget < searchRadiusSquared)
            {
                return (*iter);
            }

        }
        return nullptr;
}



void Pathing_Walker::drawNodes(sf::RenderWindow* render)
{



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


