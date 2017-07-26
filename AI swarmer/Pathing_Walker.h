#pragma once
#include <algorithm>
#include <list>
#include "source\Pathing_node.h"
#include "source\Pathing_edge.h"

typedef std::list<Pathing_node*> NodeList;

class Pathing_Walker
{
public:
    Pathing_Walker();
    ~Pathing_Walker();
    std::list<Pathing_node*> allNodes;
    //built from wikipedia's psuedocode mostly
    void Astar(NodeList, Pathing_node* startNode, Pathing_node* targetNode);
    //tracks back through the connected nodes to make a path
    void buildPath(Pathing_node* start, Pathing_node* end);
    //return the lowest Fscore
    Pathing_node* bestScore(NodeList openList);
    //generates a default node block
    std::list<Pathing_node*> generateNodes();

};

