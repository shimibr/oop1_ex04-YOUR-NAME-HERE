#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "Toolbar.h"
#include "Loc_Object.h"


class Board 
{
public:
	Board();
	void ran();
	void print_window(sf::RenderWindow& window, Toolbar& toolbar);
	void deleteObject(const int x, const int y);
	void pushObject(const int x,const int y,Object* object);

private:
	void update_window(sf::RenderWindow& window);
	void print_toolbar(sf::RenderWindow& window, Toolbar& toolbar);
	
	std::vector<Loc_Object> m_LocObjects;
};