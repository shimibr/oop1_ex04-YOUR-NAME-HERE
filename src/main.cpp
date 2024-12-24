#pragma once

#include <SFML/Graphics.hpp>
#include "Toolbar.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Toolbar Example");

    // ����� Toolbar ������ ���������� ���� toolbar.txt
    //Toolbar toolbar("../resources/toolbar.txt");
    Object o1(0, 0, '!');

    // ����� ����
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // ����� ����
        window.clear();

        // ���� �� ���������� �-toolbar
        //for (const auto& obj : toolbar.getObjects()) {
        //    window.draw(obj.getSprite());
        //}
        window.draw(o1.getSprite());

        // ���� ����� �� ����
        window.display();
    }

    return 0;
}
