#pragma once
#include <vector>
#include "Pathing_edge.h"
class Pathing_node
{
public:
    Pathing_node();
    ~Pathing_node();
    //the node that this node can be most efficiently reached from
    Pathing_node* m_parent;
    //all nodes this node is connected to
    std::vector<Pathing_edge> connections;
    
    float Gscore;
    float Hscore;
    float Fscore;
};
