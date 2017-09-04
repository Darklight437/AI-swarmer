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
    //returns a pointer to the first node in the list that is linked to the end node through the best possible path
    Pathing_node* Astar(NodeList, Pathing_node* startNode, Pathing_node* targetNode);

    //tracks back through the connected nodes and evaluates the cheapest path
    //mostly just in use to simplify code in a*
    Pathing_node* buildPath(Pathing_node* start, Pathing_node* end);

    //return the lowest Fscore
    Pathing_node* bestScore(NodeList openList);

    //get the sistance between two nodes
    float distBetween(Pathing_node* currNode, Pathing_node* targetNode);

    //generates a default node block
    void generateNodes();


    void generateSingleNode();


    void movenodes();


    void drawNodes(sf::RenderWindow* render);



    //square root of the radius to check for nodes
    float squaredRadius = 14400;
    //searches all the nodes currently in the list adding the ones that fall within the squared radius
    void linkNode(Pathing_node* currentNode);

    


    

};

