#pragma once
#include <algorithm>
#include "source\Node_holder.h"
#include "source\Pathing_node.h"
#include "source\Pathing_edge.h"

class Pathing_Walker
{
public:
    Pathing_Walker();
    ~Pathing_Walker();

    void Astar(Pathing_node* startNode, Pathing_node* endNode);
    void buildPath(Pathing_node* start, Pathing_node* end);

};

