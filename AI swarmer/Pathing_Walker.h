#pragma once
#include <algorithm>
#include <list>
#include "source\Node_holder.h"
#include "source\Pathing_node.h"
#include "source\Pathing_edge.h"

class Pathing_Walker
{
public:
    Pathing_Walker();
    ~Pathing_Walker();
    //built from wikipedia's psuedocode mostly
    void Astar(Pathing_node* startNode, Pathing_node* endNode);
    void buildPath(Pathing_node* start, Pathing_node* end);
    //return the lowest Fscore
    Pathing_node* bestScore(std::list<Pathing_node*> openList);

};

