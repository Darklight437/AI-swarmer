#include "Gameobject.h"
#include <Windows.h>
#include "deltaClock.h"

Gameobject::Gameobject()
{
    
}

Gameobject::Gameobject(std::string spriteFileName)
{
    if (!m_texture.loadFromFile(spriteFileName))
    {
        //freak out somehow maybe an exception
    }
    m_texture.setSmooth(false);
    m_sprite.setTexture(m_texture);
    
}


Gameobject::~Gameobject()
{
}


 std::string Gameobject::getExecutableFolder()
{
    char buffer[MAX_PATH];
    GetModuleFileName(NULL, buffer, MAX_PATH);
    char *pos;
    if (pos = strrchr(buffer, '\\'))
    {
        *pos = 0;
    }

    return buffer;
}

 void Gameobject::setPosition(sf::Vector2f position)
 {
     m_position = position;
 }

 void Gameobject::setPosition(float x, float y)
 {
     m_position.x = x;
     m_position.y = y;
 }


 void Gameobject::update()
 {
    //all movement happens HERE
    //deltatime should live here
     

     m_position += m_acceleration * (float)CLOCK->getelapsedTime();
     m_sprite.move(m_position);

     
 }

