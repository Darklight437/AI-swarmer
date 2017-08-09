#pragma once
#include <algorithm>
#include <list>
#include "Pathing_node.h"
#include "Pathing_edge.h"

typedef std::list<Pathing_node*> NodeList;

class Pathing_Walker
{
public:
    Pathing_Walker();
    ~Pathing_Walker();
    std::list<Pathing_node*> allNodes;
    std::list<Pathing_edge*> allEdges;
    //built from wikipedia's psuedocode mostly
    void Astar(NodeList, Pathing_node* startNode, Pathing_node* targetNode);

    //tracks back through the connected nodes to make a path
    void buildPath(Pathing_node* start, Pathing_node* end);

    //return the lowest Fscore
    Pathing_node* bestScore(NodeList openList);

    //generates a default node block
    std::list<Pathing_node*> generateNodes();

    //adds edges for a given node if there are other nodes present
    void addEdges(Pathing_node*);

    //square root of the radius to check for nodes
    float squaredRadius;
    void radiusForCheck(std::list <Pathing_node*> nodesToSearch, Pathing_node* currentNode);


};

