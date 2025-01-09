#include "Board.h"
#pragma once


Board::Board()
{
	m_texture.loadFromFile("background.png");
}
//=========================================
void Board::delete_object(const Location location)
{
	for (auto it = m_LocObjects.begin(); it != m_LocObjects.end(); ++it)
	{
		if (it->location.row == location.row  && it->location.col == location.col)
		{
			m_LocObjects.erase(it);
			break;
		}
	}
}
//====================================================
void Board::push_object(const Location location, Object* object)
{
	delete_object(location);
	Loc_Object tamp(location, object);
	m_LocObjects.push_back(tamp);
}
//=====================================
void Board::clear_objects()
{
	m_LocObjects.clear();
}
//====================================================
void Board::shadow_object(sf::RenderWindow& window, Object* object)const
{
		sf::Sprite sprite;
		sprite.setTexture(object->getTexture());
		sprite.setColor(sf::Color(255, 255, 255, 150));
		
		sf::Vector2i locMouse = sf::Mouse::getPosition(window);
		if (locMouse.x < 0 || locMouse.x >= window.getSize().x || locMouse.y < 0 || locMouse.y >= window.getSize().y)
			return;
		else if (locMouse.y / Entity::SIZE_PIXEL == 0)
		{
			sprite.setScale(0.7, 0.7);
			sprite.setPosition(locMouse.x , locMouse.y - Entity::SIZE_PIXEL/2);
		}
		else
		sprite.setPosition(locMouse.x - locMouse.x % Entity::SIZE_PIXEL, locMouse.y - locMouse.y % Entity::SIZE_PIXEL);


		window.draw(sprite);
}
//=======================================
void Board::update_window(sf::RenderWindow& window)
{
	for (int i = 0; i < m_LocObjects.size(); i++)
	{
		sf::Sprite sprite;
		sprite.setTexture(m_LocObjects[i].object->getTexture());
		sprite.setPosition(m_LocObjects[i].location.col * Entity::SIZE_PIXEL
						, m_LocObjects[i].location.row * Entity::SIZE_PIXEL);
		window.draw(sprite);
	}
}
//===========================
void Board::print_toolbar(sf::RenderWindow& window, Toolbar& toolbar)const
{
	int size_object = window.getSize().x / toolbar.get_size();
	for (int i = 0; i < toolbar.get_size(); i++)
	{
		sf::Sprite sprite;
		sprite.setTexture(toolbar.get_object(i).getTexture());
		sprite.setScale(size_object*0.02, 1);
		sprite.setPosition(i * size_object,0);
		window.draw(sprite);
	}
}
//======================================
void Board::print_background(sf::RenderWindow& window)const
{	
	sf::Sprite sprite;
	sprite.setTexture(m_texture);

	for (int row = Entity::SIZE_PIXEL; row < window.getSize().y; row += Entity::SIZE_PIXEL)
	{
		for (int col = 0; col < window.getSize().x; col += Entity::SIZE_PIXEL)
		{
			sprite.setPosition(col, row); 
			window.draw(sprite);
		}
	}
}
//======================================
void Board::print_window(sf::RenderWindow& window, Toolbar& toolbar, Object* object)
{
	window.clear();
	print_toolbar(window, toolbar);
	print_background(window);
	update_window(window);

	if (object)
	shadow_object(window,object);
	
	window.display();
}
//=======================================
void Board::show_save_success_window()const
{
	sf::RenderWindow successWindow(sf::VideoMode(300, 150), "System message");

	sf::Font font;
	font.loadFromFile("font.ttf");
	sf::Text text;
	text.setFont(font);
	text.setString("Successfully saved!");
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::Blue);
	text.setStyle(sf::Text::Bold);

	sf::FloatRect textRect = text.getLocalBounds();
	text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	text.setPosition(150.0f, 75.0f);

	successWindow.clear(sf::Color::White);
	successWindow.draw(text);
	successWindow.display();

	std::this_thread::sleep_for(std::chrono::seconds(1));
	successWindow.close();
}


