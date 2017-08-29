#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "Agent.h"


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
  //occur every frame updating the transform if it has ben changed etc
  void update();

  sf::Sprite m_sprite;
protected:
    sf::Texture m_texture;
    sf::Vector2f m_position;
    sf::Vector2f m_velocity;
};

