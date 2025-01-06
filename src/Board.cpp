#include "Board.h"
#pragma once


Board::Board()
{
}
//=========================================
void Board::deleteObject(const int x, const int y)
{
	for (auto it = m_LocObjects.begin(); it != m_LocObjects.end(); ++it)
	{
		if (it->getLocation().row == y && it->getLocation().col == x)
		{
			m_LocObjects.erase(it);
			break;
		}
	}
}
//====================================================
void Board::pushObject(const int x, const int y, Object* object)
{
	deleteObject(x, y);
	Loc_Object tamp(y, x, object);
	m_LocObjects.push_back(tamp);
}
//=======================================
void Board::update_window(sf::RenderWindow& window)
{
	for (int i = 0; i < m_LocObjects.size(); i++)
	{
		sf::Sprite sprite;
		sprite.setTexture(m_LocObjects[i].getTexture());
		sprite.setPosition(m_LocObjects[i].getLocation().col * 50, m_LocObjects[i].getLocation().row * 50);
		window.draw(sprite);
	}
}
//===========================
void Board::print_toolbar(sf::RenderWindow& window, Toolbar& toolbar)
{
	
	for (int i = 0; i < toolbar.getSize(); i++)
	{
		sf::Sprite sprite;
		sprite.setTexture(toolbar.getObject(i).getTexture());
		sprite.setPosition(i * 50,0);
		window.draw(sprite);
	}
}
//======================================
void Board::print_window(sf::RenderWindow& window, Toolbar& toolbar)
{
	window.clear();
	print_toolbar(window, toolbar);
	update_window(window);
	window.display();
}

