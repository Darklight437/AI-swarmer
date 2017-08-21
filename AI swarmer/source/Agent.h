#pragma once
//#include <SFML\Graphics\Transformable.hpp>
#include <vector>
#include "Behavior.h"


class Agent
{
public:
    Agent();
    ~Agent();
    
   
    
    

    std::vector<Behavior*> behaviors;
    
};

