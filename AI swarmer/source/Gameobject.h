#pragma once
#include <SFML/Graphics.hpp>


class Gameobject
{
public:
    Gameobject();
    virtual ~Gameobject();
    virtual void loadSprite() = 0;
    std::string getExecutableFolder() const;


protected:
    sf::Texture m_texture;


};

