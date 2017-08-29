
#include "Gameobject.h"
#include "master.h"
#include "Pathing_Walker.h"
#include <Windows.h>
#include <SFML\Graphics.hpp>
#include "deltaClock.h"


int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR cmdLine, int cmdShow)
{
    sf::RenderWindow window(sf::VideoMode(1680, 1060), "Swarmlings");
    sf::RenderWindow* windowPtr = &window;
    Pathing_Walker* m_NodeManager = new Pathing_Walker;

    // run startup constructor for the game(sorta)
    

    //make gameobjects
    Gameobject* miniship = new master();
    

    m_NodeManager->generateNodes();




    while (window.isOpen())
    {
        CLOCK->restart();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();   
        }
        
        

        window.clear();
        //tell objects to draw here
        
        //moves the objext towards the target this will have the a* as the target eventually
        ((master*)miniship)->steer(m_NodeManager->allNodes.back()->getPos());
        miniship->update();
        m_NodeManager->drawNodes(windowPtr);

        window.draw(miniship->m_sprite);

        


        window.display();
    } //end loop

    delete m_NodeManager;
    delete miniship;

    return 0;
}


