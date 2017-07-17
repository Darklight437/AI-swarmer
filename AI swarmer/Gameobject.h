#pragma once
#include <SFML/Graphics.hpp>


class Gameobject
{
public:
    Gameobject();
    virtual ~Gameobject();
    virtual void loadSprite() = 0;


protected:
    sf::Texture m_texture;

};

