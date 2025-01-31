#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "Toolbar.h"
#include <thread>
#include "io.h"

class Board 
{
public:
	Board();
	void print_window(sf::RenderWindow& window, Toolbar& toolbar, Object* object);
	void show_save_success_window()const;
	void delete_object(const Location location);
	void push_object(const Location location, Object* object);
	void clear_objects();

private:
	void shadow_object(sf::RenderWindow& window, Object* object, const int sizeObjectToolbar)const;
	void update_window(sf::RenderWindow& window, const int sizeObjectToolbar);
	void print_toolbar(sf::RenderWindow& window, Toolbar& toolbar)const;
	void print_background(sf::RenderWindow& window, const int sizeObjectToolbar)const;
	
	std::vector<Loc_Object> m_LocObjects;
	sf::Texture m_texture;
};