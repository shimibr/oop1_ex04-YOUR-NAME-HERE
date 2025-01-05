#include "Board.h"
#pragma once


Board::Board(const int i, const int j)
	: m_window(sf::VideoMode(i*50,(j+1)*50), "Window example") 
{
	
}
//=============================
void Board::ran()
{
	Object* object = &getObject(0);

	while (m_window.isOpen())
	{
		print_window();
		sf::Event event;
		while (m_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) 
				m_window.close();


			else if (event.type == sf::Event::MouseButtonPressed)
			{

				sf::Vector2i mousePosition = sf::Mouse::getPosition(m_window);

				if (mousePosition.y >= 0 && mousePosition.y < 50)
				{
					int index = mousePosition.x / 50;

					if(index < getSize())
					object = &getObject(index);
				}
				else if (mousePosition.y >= 50 && mousePosition.y < m_window.getSize().y)
				{
					int x = mousePosition.x / 50, y = mousePosition.y / 50;
					if (object->getType() == ' ')
						deleteObject(x,y);
					else
					{
						Loc_Object tamp(y, x, object);
						m_LocObjects.push_back(tamp);

					}
				}
			}

		}
	


	}
}
//=========================================
void Board::deleteObject(const int x, const int y)
{
	for (int i = 0; i < m_LocObjects.size(); i++)
	{

	}
}
//=======================================
void Board::update_window()
{
	for (int i = 0; i < m_LocObjects.size(); i++)
	{
		sf::Sprite sprite;
		sprite.setTexture(m_LocObjects[i].getTexture());
		sprite.setPosition(m_LocObjects[i].getLocation().col * 50, m_LocObjects[i].getLocation().row * 50);
		m_window.draw(sprite);
	}
}
//===========================
void Board::print_toolbar()
{
	
	for (int i = 0; i < getSize(); i++)
	{
		sf::Sprite sprite;
		sprite.setTexture(getObject(i).getTexture());
		sprite.setPosition(i * 50,0);
		m_window.draw(sprite);
	}
}
//======================================
void Board::print_window()
{
	m_window.clear();
	print_toolbar();
	update_window();
	m_window.display();
}

