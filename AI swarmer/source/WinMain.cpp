
#include "Gameobject.h"
#include "master.h"
#include "Pathing_Walker.h"
#include <Windows.h>
#include <SFML\Graphics.hpp>
#include <SFML\System\Clock.hpp>


int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR cmdLine, int cmdShow)
{
    sf::RenderWindow window(sf::VideoMode(1680, 1060), "Swarmlings");
    sf::RenderWindow* windowPtr = &window;
    Pathing_Walker* m_NodeManager = new Pathing_Walker;
    sf::Clock mainClock;
    sf::Time deltaTime;
    // run startup constructor for the game(sorta)
    

    //make gameobjects
    Gameobject* miniship = new master();
    

    m_NodeManager->generateNodes();

    mainClock.restart();


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
        deltaTime = mainClock.restart();


        
        m_NodeManager->drawNodes(windowPtr);
        window.draw(miniship->m_sprite);

        


        window.display();
    } //end loop

    delete m_NodeManager;
    delete miniship;

    return 0;
}


