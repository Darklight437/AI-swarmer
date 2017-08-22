#include "master.h"



void master::loadSprite()
{
    m_texture.loadFromFile((getExecutableFolder() + "/sprites/rocket-drone.png").c_str());
    m_texture.setSmooth(false);
    m_sprite.setTexture(m_texture);
}

master::master()
{
}


master::~master()
{
}
