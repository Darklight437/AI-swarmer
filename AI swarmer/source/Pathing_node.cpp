#include "Pathing_node.h"



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
    for (iter = nodesToSearch.begin; iter < nodesToSearch.end; iter++)
    {
        if ((*iter) == this)
        {

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


