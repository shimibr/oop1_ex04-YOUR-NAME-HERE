#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "Toolbar.h"
#include "Loc_Object.h"
#include <thread>


class Board 
{
public:
	Board();
	void print_window(sf::RenderWindow& window, Toolbar& toolbar);
	void show_save_success_window();
	void delete_object(Location location);
	void push_object(Location location, Object* object);
	void clear_objects();

private:
	void update_window(sf::RenderWindow& window);
	void print_toolbar(sf::RenderWindow& window, Toolbar& toolbar);
	void print_background(sf::RenderWindow& window);
	
	std::vector<Loc_Object> m_LocObjects;
	sf::Texture m_texture;
};