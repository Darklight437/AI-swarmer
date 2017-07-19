#pragma once
//forward dec
class Pathing_node;

class Pathing_edge
{
public:
    Pathing_edge();
    ~Pathing_edge();
    float getCost();
private:
    float m_cost;
    Pathing_node* Node1;
    Pathing_node* Node2;
};

