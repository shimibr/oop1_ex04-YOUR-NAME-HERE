#pragma once
#include "Board.h"

class Controler
{
public:
    Controler();
    void run();

private:
    void fill_from_file(sf::RenderWindow& window);
};


//#pragma once
//
//#include <SFML/Graphics.hpp>
//#include <SFML/System.hpp>
//#include <SFML/Window.hpp>
//#include <SFML/Audio.hpp>
//#include <SFML/Network.hpp>
//
//
//class Controler
//{
//public:
//	Controler();
//	void run();
//
//
//private:
//	void fill_from_file(sf::RenderWindow& window);
//
//
//
//
//};
