#pragma once

#include <SFML/Graphics.hpp>
#include "Toolbar.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Toolbar Example");
 
    Toolbar toolbar("toolbar.txt");
   
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        for (int i = 0; i < toolbar.getSize(); i++)
        {
            //toolbar(i).getSprite().setPosition(50*i,0);
            window.draw(toolbar(i).getSprite());
        }

        window.display();
    }

    return 0;
}
