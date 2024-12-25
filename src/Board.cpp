#include "Board.h"
#include <SFML/Graphics.hpp>


Board::Board(const int i, const int j)
	: m_window(sf::VideoMode(i*50,(j+1)*50), "Window example")
{
	
}
//=============================
void Board::ran()
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

				if (mousePosition.y >= 0 && mousePosition.y < 50)
				{
					int index = mousePosition.x / 50;
					if (index >= 0 && index < m_objects.size())
						insert_objects(m_objects[index]);
					
				}
			}

		}
	


	}
}
//=======================================
void Board::insert_objects(Object& object)
{
	while (m_window.isOpen())
	{
		update_window();
		sf::Event event;
		while (m_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				m_window.close();



		}
	}
}
//==================================
void Board::update_window()
{
	m_window.clear();
	for (int i = 0; i < m_objects.size(); i++)
	{
		m_window.draw(m_objects[i]);
	}
	m_window.display();
}
