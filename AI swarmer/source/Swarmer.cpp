#include "Swarmer.h"



Swarmer::Swarmer()
{
    loadSprite();
    myAgent.flock = true;
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

void Swarmer::updateNeighbours(std::list<Swarmer*> neighbours)
{

    m_neighbours = neighbours;
    //gets the nearby boids for this frame
    //puts em in a local list
    

}



