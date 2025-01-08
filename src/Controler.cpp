#pragma once
#include "Controler.h"
#include <iostream>

Controler::Controler()
	:m_sizeObject(50), m_delitWindow(true)
{ }
//===========================
void Controler::run()
{
	int i, j;


	while (m_delitWindow)
	{
		loading_window(i, j);

		sf::RenderWindow window = sf::RenderWindow(sf::VideoMode(i * m_sizeObject, (j + 1) * m_sizeObject), "Window example");
		Object* object = &m_toolbar.getObject(0);

		while (window.isOpen())
		{
			m_board.print_window(window, m_toolbar);
			sf::Event event;

			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					m_delitWindow = false;
					window.close();
				}
				else if (event.type == sf::Event::MouseButtonPressed)
				{
					sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
					int col = mousePosition.x / m_sizeObject;
					int row = mousePosition.y / m_sizeObject;

					if (row == 0)//mousePosition.y >= 0 && mousePosition.y < m_sizeObject)
					{
						if (col < m_toolbar.getSize())
							object = &m_toolbar.getObject(col);

						if (object->getType() == 'X')
						{
							m_loadFile.update_data();
							std::cout << "The file has been updated" << std::endl;
							object = &m_toolbar.getObject(0);
							break;
						}
						if (object->getType() == 'C')
						{
							delitWindow();
							window.close();
						}

					}


					if (mousePosition.y >= m_sizeObject && mousePosition.y < window.getSize().y)
					{
						if (object->getType() == '/')
						{
							robot_control(row, col, m_toolbar.getObject(0));
						}
						init_Object(object, Location(row, col));

					}
				}
			}
		}
	}
}
//==========================================
void Controler::loading_window(int& i, int& j)
{
	if (!m_loadFile.get_is_file())
	{
		std::cout << "Please enter the window height: ";
		std::cin >> i;
		std::cout << "Please enter the window width: ";
		std::cin >> j;
		std::cout << "excellent! The window is already up" << std::endl;
		m_loadFile.set_size(Location(j, i));
	}
	else
	{
		std::cout << "Please wait - we are already continuing the editing :) " << std::endl;

		j = m_loadFile.get_row_size();
		i = m_loadFile.get_col_size();
		fill_from_file();
	}
		m_robotLocation = m_loadFile.get_loc_robot();
}
//================================================
void Controler::robot_control(const int row, const int col,Object& Tdelete)
{
		if(m_loadFile.check_if_robot(Location(m_robotLocation.row-1, m_robotLocation.col)))
			init_Object(&Tdelete, m_robotLocation);
	
	m_robotLocation.col = col;
	m_robotLocation.row = row;
}
//==========================================
void Controler::delitWindow()
{
	m_loadFile.clear_data();
	m_board.clearObjects();
}

//=================================
void Controler::fill_from_file()
{
	Char_Location type_location;
	Object* object = &m_toolbar.getObject(0);
	while (m_loadFile.get_from_file(type_location))
	{
		for (int i = 0; i < m_toolbar.getSize(); i++)
		{
			if (type_location.type == m_toolbar.getObject(i).getType())
			{
				object = &m_toolbar.getObject(i);
				break;
			}
		}
		type_location.location.row++;
		m_board.pushObject(type_location.location, object);
	}
}
//================================================
void Controler::init_Object(Object* object, Location location)
{
	if (object->getType() == ' ')
		m_board.deleteObject(location);

	else
		m_board.pushObject(location, object);

	location.row--;
	m_loadFile.set_to_file(Char_Location(location, object->getType()));
}
//================================================
