#pragma once
#include <vector>
#include "Pathing_edge.h"
class Pathing_node
{
public:
    Pathing_node();
    ~Pathing_node();
    Pathing_node* m_parent;

    std::vector<Pathing_edge> connections;

    float Gscore;
    float Hscore;
    float Fscore;
};

