#pragma once
#include <SFML/Graphics.hpp>
#include <string>


class Gameobject
{
public:
    Gameobject();
    Gameobject(std::string spriteFileName);
    virtual ~Gameobject();
    //virtual void loadSprite() = 0;
  static std::string getExecutableFolder();

  sf::Sprite m_sprite;
protected:
    sf::Texture m_texture;


};

