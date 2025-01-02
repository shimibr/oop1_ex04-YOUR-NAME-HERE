#include "Board.h"
#pragma once

#include "Board.h"


Board::Board(const int i, const int j)
	: m_window(sf::VideoMode(i*50,(j+1)*50), "Window example") 
{
	
}
//=============================
void Board::ran()
{
	print_toolbar();

	while (m_window.isOpen())
	{
		update_window();
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
					if (index >= 0 && index < getSize())
						insert_objects(getObject(index));
					
				}
			}

		}
	


	}
}
//=======================================
void Board::insert_objects(Object & object)
{
		while (m_window.isOpen())
		{
			update_window();
			sf::Event event;
			while (m_window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					m_window.close();

				else if (event.type == sf::Event::MouseButtonPressed)
				{

					sf::Vector2i mousePosition = sf::Mouse::getPosition(m_window);

					if (mousePosition.y >= 0 && mousePosition.y < 50) {}

				}
			}
		}
}
//==================================
void Board::update_window()
{
	m_window.clear();
	for (int i = 0; i < m_LocObjects.size(); i++)
	{
		sf::Sprite sprite;
		sprite.setTexture(m_LocObjects[i].getTexture());
		sprite.setPosition(m_LocObjects[i].getLocation().col * 50, m_LocObjects[i].getLocation().row * 50);
	}
	m_window.display();
}
//===========================
void Board::print_toolbar()
{
	m_window.clear();
	for (int i = 0; i < getSize(); i++)
	{
		sf::Sprite sprite;
		sprite.setTexture(getObject(i).getTexture());
		sprite.setPosition(0,i * 50);
	}
	m_window.display();

}

