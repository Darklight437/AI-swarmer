#pragma once
#include <list>
#include "Pathing_node.h"
class Node_holder
{
public:
    Node_holder();
    ~Node_holder();



private:

    std::list<Pathing_node> nodelist;
    

};

