#pragma once
#include "Controler.h"
#include <iostream>

Controler::Controler()
	:m_deleteWindow(true), m_robotLocation{ 0,0 }
{ }
//===========================
void Controler::run()
{
	int i, j;
	while (m_deleteWindow)
	{
		loading_window(i, j);
		sf::RenderWindow window = sf::RenderWindow(sf::VideoMode(i * Entity::SIZE_PIXEL, (j + 1) * Entity::SIZE_PIXEL), "Stage editing panel");
		Object* object = &m_toolbar.get_object(0);

		while (window.isOpen())
		{
			m_board.print_window(window, m_toolbar);
			sf::Event event;

			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					m_deleteWindow = false;
					window.close();
				}
				else if (event.type == sf::Event::MouseButtonPressed)
				{
					sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
					Location mouseLoc(mousePosition.y / Entity::SIZE_PIXEL, mousePosition.x / Entity::SIZE_PIXEL);

					if (mouseLoc.row == 0)
						toolbar_event(window, object, mouseLoc);

					if (mousePosition.y >= Entity::SIZE_PIXEL && mousePosition.y < window.getSize().y)
						board_event(window, object, mouseLoc);
				}
			}
		}
	}
}
//==========================================
void Controler::toolbar_event(sf::RenderWindow& window, Object*& object, Location mouseLoc)
{
	if (mouseLoc.col < m_toolbar.get_size())
		object = &m_toolbar.get_object(mouseLoc.col);

	if (object->getType() == Entity::SAVE)
	{
		oction_save(object);
		return;
	}
	if (object->getType() == Entity::CLEAN_BOARD)
	{
		delete_window();
		window.close();
	}

}
//==========================================
void Controler::board_event(sf::RenderWindow& window, Object*& object, Location mouseLoc)
{
	if (object->getType() == Entity::ROBOT)
	{
		robot_control(mouseLoc.row, mouseLoc.col, m_toolbar.get_object(0));
	}
	init_Object(object, Location(mouseLoc.row, mouseLoc.col));
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
void Controler::robot_control(const int row, const int col, Object& Tdelete)
{
	if (m_loadFile.check_if_robot(Location(m_robotLocation.row - 1, m_robotLocation.col)))
		init_Object(&Tdelete, m_robotLocation);

	m_robotLocation = Location(row, col);
}
//==========================================
void Controler::oction_save(Object* object)
{
	m_loadFile.update_data();
	m_board.show_save_success_window();
	std::cout << "The file has been updated" << std::endl;
	object = &m_toolbar.get_object(0);
}
//==========================================
void Controler::delete_window()
{
	m_loadFile.clear_data();
	m_board.clear_objects();
}

//=================================
void Controler::fill_from_file()
{
	Char_Location type_location;
	Object* object = &m_toolbar.get_object(0);
	while (m_loadFile.get_from_file(type_location))
	{
		for (int i = 0; i < m_toolbar.get_size(); i++)
		{
			if (type_location.type == m_toolbar.get_object(i).getType())
			{
				object = &m_toolbar.get_object(i);
				break;
			}
		}
		type_location.location.row++;
		m_board.push_object(type_location.location, object);
	}
}
//================================================
void Controler::init_Object(Object* object, Location location)
{
	if (object->getType() == Entity::FREE_SPASE)
		m_board.delete_object(location);

	else
		m_board.push_object(location, object);

	location.row--;
	m_loadFile.set_to_file(Char_Location(location, object->getType()));
}
//================================================
