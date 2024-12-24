#pragma once

#include <SFML/Graphics.hpp>
#include "Location.h"
#include <ostream>

class Object
{
public:
	Object();
	Object(int x, int y, char type);
	const sf::Sprite& getSprite() const;
	void loadTexture();

private:
	Location m_location;
	sf::Texture m_texture;
	sf::Sprite m_sprite;
	char m_type;



};