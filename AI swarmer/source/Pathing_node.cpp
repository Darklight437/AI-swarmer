#include "Pathing_node.h"
#include <algorithm>


Pathing_node::Pathing_node()
{
}


Pathing_node::~Pathing_node()
{
}

void Pathing_node::draw()
{
    
}

void Pathing_node::linkToNodes()
{
    //

}

void Pathing_node::radiusForCheck(std::list <Pathing_node*> nodesToSearch)
{

    std::list<Pathing_node*> LinkedNodes;
    std::list<Pathing_node*>::iterator iter;
    for (iter = nodesToSearch.begin(); iter != nodesToSearch.end(); iter++)
    {
        if ((*iter) != this)
        {
            
            sf::Vector2f dispVect = this->m_position - (*iter)->m_position;
            
            float squaredMagnitude = (dispVect.x * dispVect.x) + (dispVect.y * dispVect.y);
            //valid range nodes
            if (squaredMagnitude < squaredRadius)
            {
                LinkedNodes.push_back(this);
            }
            

        }
    }// /for
    EdgeList::iterator edgeSearch;

    for (iter = LinkedNodes.begin(); iter != LinkedNodes.end(); iter++)
    {
        for (edgeSearch = connections.begin; edgeSearch != connections.end; edgeSearch++)
        {
            if ((*edgeSearch)->Node1 != this && (*edgeSearch)->Node2 != this);
            {
                Pathing_edge* newEdge = new Pathing_edge;
                newEdge->Node1 = this;
                newEdge->Node2 = (*iter);
                connections.push_back(newEdge);
                
                //work out how to store these
            }

        }
        
    } // /for 

    
    
    

    

}


