#include "Gameobject.h"
#include <Windows.h>


Gameobject::Gameobject()
{
    
}

Gameobject::Gameobject(std::string spriteFileName)
{

}


Gameobject::~Gameobject()
{
}


std::string Gameobject::getExecutableFolder() const
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

