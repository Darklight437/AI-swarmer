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
            
            
            




        }
    }
    //look at the list of all nodes, (ignore self)
    //loop over and get a vector for each from your poition (oh boy how to do that)

    //if the sqrt of the vector is less than the saved radius sqrt
    //its good and you put it in a temp vector of linked nodes 

    //once all nodes have been checked go through the vector,
    //create an edge between the node if there isnt one already
    //delete nodes from vector and fill new vector with edges

    

}


