#include "Board.h"
#pragma once


Board::Board()
{
	m_texture.loadFromFile("background.png");
}
//=========================================
void Board::deleteObject(Location location)
{
	for (auto it = m_LocObjects.begin(); it != m_LocObjects.end(); ++it)
	{
		if (it->getLocation().row == location.row  && it->getLocation().col == location.col)
		{
			m_LocObjects.erase(it);
			break;
		}
	}
}
//====================================================
void Board::pushObject(Location location, Object* object)
{
	deleteObject(location);
	Loc_Object tamp(location, object);
	m_LocObjects.push_back(tamp);
}
//=====================================
void Board::clearObjects()
{
	m_LocObjects.clear();
}
//=======================================
void Board::update_window(sf::RenderWindow& window)
{
	for (int i = 0; i < m_LocObjects.size(); i++)
	{
		sf::Sprite sprite;
		sprite.setTexture(m_LocObjects[i].getTexture());
		sprite.setPosition(m_LocObjects[i].getLocation().col * SIZE_PIXEL
						, m_LocObjects[i].getLocation().row * SIZE_PIXEL);
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
		sprite.setPosition(i * SIZE_PIXEL,0);
		window.draw(sprite);
	}
}
//======================================
void Board::print_background(sf::RenderWindow& window)
{
	//sf::Texture texture;
	//texture.loadFromFile("background.png");
	
	sf::Sprite sprite;
	sprite.setTexture(m_texture);

	for (int row = SIZE_PIXEL; row < window.getSize().y; row+=SIZE_PIXEL)
	{
		for (int col = 0; col < window.getSize().x; col+=SIZE_PIXEL)
		{
			sprite.setPosition(col, row); 
			window.draw(sprite);
		}
	}
}
//======================================
void Board::print_window(sf::RenderWindow& window, Toolbar& toolbar)
{
	window.clear();
	print_toolbar(window, toolbar);
	print_background(window);
	update_window(window);
	window.display();
}

