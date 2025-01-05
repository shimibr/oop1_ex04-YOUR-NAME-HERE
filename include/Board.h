#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "Toolbar.h"
#include "Loc_Object.h"


class Board :public Toolbar
{
public:
	Board(const int i = 0,const int j = 0);
	void ran();

private:
	void deleteObject(const int x, const int y);
	//bool isOccupied(const int x, const int y);
	void update_window();
	void print_toolbar();
	void print_window();
	
	std::vector<Loc_Object> m_LocObjects;
	sf::RenderWindow m_window;
	Loc_Object* m_IsRobot;
};