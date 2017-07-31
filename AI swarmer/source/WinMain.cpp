
#include "Gameobject.h"
#include "Pathing_Walker.h"
#include <Windows.h>
#include <SFML/Graphics.hpp>

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR cmdLine, int cmdShow)
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Swarmlings");

    // run startup constructor for the game(sorta)
    Gameobject* Testobject = new Gameobject(Gameobject::getExecutableFolder() + "\\sprites\\rocket-drone.png");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        //tell objects to draw here
        
        window.draw(Testobject->m_sprite);





        window.display();
    }

    return 0;
}