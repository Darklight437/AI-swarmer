#pragma once
//#include <SFML\Graphics\Transformable.hpp>
#include <vector>
#include "Behavior.h"
#include "Seek.h"
#include "Flock.h"

enum class NeighbourTyp {COHERE, SEP, ALIGN};

struct FlockingNeighbours
{
    std::list<Gameobject*> cohereNeighbours;
    std::list<Gameobject*> separateNeighbours;
    std::list<Gameobject*> alignNeighbours;
};

class Agent
{
public:
    Agent();
    ~Agent();
    
    sf::Vector2f getSteeringForce(sf::Vector2f myPosition, sf::Vector2f targetPosition);
    sf::Vector2f getFlockForce(Gameobject* thisObject, sf::Vector2f targetPos);
    void addAlign(Gameobject* neighbour);
    void addCohere(Gameobject* neighbour);
    void addSeparate(Gameobject* neighbour);
    void removeNeighbour(Gameobject* neighbour, NeighbourTyp T);
    void setTopSpeed(float speed);

    Behavior* seekBehavior = new Seek;
    Behavior* FlockBehavior = new Flock;
    
    

private:
    float movementSpeed;
    sf::Vector2f steeringForce;
    
    FlockingNeighbours Neighbours;
};

