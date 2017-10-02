#include "Swarmer.h"

#include "Agent.h"

Swarmer::Swarmer()
{
    loadSprite();
    myAgent->setTopSpeed(200);
}


Swarmer::~Swarmer()
{
}

void Swarmer::loadSprite()
{
    m_texture.loadFromFile((getExecutableFolder() + "/sprites/Triangle.png"));
    m_texture.setSmooth(false);
    m_sprite.setTexture(m_texture);
    m_sprite.setOrigin(sf::Vector2f(m_sprite.getGlobalBounds().width / 2, m_sprite.getGlobalBounds().height / 2));
}





