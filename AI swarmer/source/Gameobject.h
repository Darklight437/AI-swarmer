#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <list>

class Agent;

class Gameobject
{
public:
    Gameobject();
    Gameobject(std::string spriteFileName);
    virtual ~Gameobject();
    //virtual void loadSprite() = 0;


  static std::string getExecutableFolder();
  void setPosition(sf::Vector2f position);
  void setPosition(float x, float y);
  void setRotation(float r);
  void steer(sf::Vector2f target);
  void flock(sf::Vector2f leader);
  sf::Vector2f getVelocity();

 
  //assigning neighbours for flocking
  void getNeighbours(std::list<Gameobject*> swarmerList);

  //occur every frame updating the transform if it has ben changed etc
  void update();

  float findDistFromMe(sf::Vector2f target);
  float find2DistFromMe(sf::Vector2f target);
  sf::Sprite m_sprite;
protected:
    Agent* myAgent;
    sf::Texture m_texture;
    sf::Vector2f m_velocity;
    sf::Vector2f m_acceleration;
};

