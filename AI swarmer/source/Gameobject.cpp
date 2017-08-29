#include "Gameobject.h"
#include <Windows.h>
#include "deltaClock.h"
#include "Vmath.h"

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
     m_velocity = position;
 }

 void Gameobject::setPosition(float x, float y)
 {
     m_velocity.x = x;
     m_velocity.y = y;
 }


 void Gameobject::update()
 {
    //all movement happens HERE
    //deltatime should live here
     

     m_velocity = m_acceleration * (float)CLOCK->getelapsedTime();
    /* if (magnitude(m_position) > 2)
     {
         normalise(m_position);
         m_position.x * 2;
         m_position.y * 2;
     }*/
     if (m_acceleration.x < 0)
     {
         m_velocity.x = 0;
     }
     m_sprite.move(m_velocity);

     
 }

