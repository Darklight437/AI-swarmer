
#include "Gameobject.h"
#include "master.h"
#include "Pathing_Walker.h"
#include <Windows.h>
#include <SFML\Graphics.hpp>
#include "deltaClock.h"


int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR cmdLine, int cmdShow)
{
    sf::RenderWindow window(sf::VideoMode(1680, 1050), "Swarmlings");
    sf::RenderWindow* windowPtr = &window;
    Pathing_Walker* m_NodeManager = new Pathing_Walker;

    // run startup constructor for the game(sorta)
    

    //make gameobjects
    Gameobject* miniship = new master();
    

    m_NodeManager->generateNodes();
    //sets the path for the walker to move from the top left to the top right
    NodeList path = m_NodeManager->Astar(m_NodeManager->allNodes, m_NodeManager->allNodes.front(), m_NodeManager->allNodes.back());
    ((master*)miniship)->setPath(path);
    float fgc = 65;

    while (window.isOpen())
    {
        CLOCK->restart();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();   
        }
        
        
        //#######################################
        //rendering segment
        //#######################################


        window.clear();
        //tell objects to draw here
        
        //moves the objext towards the target this will have the a* as the target eventually

        //put a* path in the arguments for steer
        //or do some sort of walker function that checks the position of miniship and feeds it the current seek target
        ((master*)miniship)->seekPath();
        miniship->update();
        
        m_NodeManager->drawNodes(windowPtr);

        window.draw(miniship->m_sprite);

        


        window.display();
    } //end loop

    delete m_NodeManager;
    delete miniship;

    return 0;
}


