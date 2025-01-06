#pragma once
#include "Controler.h"
#include <iostream>

Controler::Controler()

{
}
//===========================
void Controler::run()
{
	int i, j;
	std::cin >> i >> j;
	sf::RenderWindow window = sf::RenderWindow(sf::VideoMode(i * m_sizeObject, (j + 1) * m_sizeObject), "Window example");

	Object* object = &m_toolbar.getObject(0);


	while (window.isOpen())
	{
		m_board.print_window(window,m_toolbar);
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			else if (event.type == sf::Event::MouseButtonPressed)
			{

				sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

				if (mousePosition.y >= 0 && mousePosition.y < m_sizeObject)
				{
					int index = mousePosition.x / m_sizeObject;

					if (index < m_toolbar.getSize())
						object = &m_toolbar.getObject(index);
				}

				else if (mousePosition.y >= m_sizeObject && mousePosition.y < window.getSize().y)
				{
					int x = mousePosition.x / m_sizeObject, y = mousePosition.y / m_sizeObject;
					if (object->getType() == ' ')
						m_board.deleteObject(x, y);

					else
					{
						m_board.pushObject(x, y, object);
					}
				}
			}

		}



	}
}


//=================================
void Controler::fill_from_file(sf::RenderWindow& window)
{
}
