#pragma once
#include <algorithm>
#include <list>
#include "source\Pathing_node.h"
#include "source\Pathing_edge.h"

class Pathing_Walker
{
public:
    Pathing_Walker();
    ~Pathing_Walker();
    //built from wikipedia's psuedocode mostly
    void Astar(std::list<Pathing_node*> allNodes);
    //tracks back through the connected nodes to make a path
    void buildPath(Pathing_node* start, Pathing_node* end);
    //return the lowest Fscore
    Pathing_node* bestScore(std::list<Pathing_node*> allNodes, Pathing_node* startNode, Pathing_node* targetNode);

};

