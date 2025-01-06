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
	fill_from_file();

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
					Location location;
					location.col = mousePosition.x / m_sizeObject;
					location.row = mousePosition.y / m_sizeObject;
			 
					init_Object(object,location);
					
				}
			}

		}



	}
}


//=================================
void Controler::fill_from_file()
{
	Char_Location type_location;
	Object* object;
	while (m_loadFile.Get_From_File(type_location))
	{
		for (int i = 0; i < m_toolbar.getSize(); i++)
		{
			if (type_location.type == m_toolbar.getObject(i).getType())
				object = &m_toolbar.getObject(i);
		}
		m_board.pushObject(type_location.location, object);
	}
}
//================================================
void Controler::init_Object(Object* object, Location location)
{////////////////////////
	if (object->getType() == ' ')
	{
		m_loadFile.Set_to_File();
		m_board.deleteObject(location);
	}
	else
	{
		m_board.pushObject(location, object);
	}
}
