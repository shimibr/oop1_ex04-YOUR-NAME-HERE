#pragma once

#include <SFML/Graphics.hpp>
#include "Toolbar.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Toolbar Example");

    // יצירת Toolbar וטעינת האובייקטים מתוך toolbar.txt
    //Toolbar toolbar("../resources/toolbar.txt");
    Object o1(0, 0, '!');

    // לולאת משחק
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // ניקוי המסך
        window.clear();

        // ציור כל האובייקטים ב-toolbar
        //for (const auto& obj : toolbar.getObjects()) {
        //    window.draw(obj.getSprite());
        //}
        window.draw(o1.getSprite());

        // הצגת הציור על המסך
        window.display();
    }

    return 0;
}
