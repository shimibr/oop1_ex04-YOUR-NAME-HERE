#pragma once

#include <SFML/Graphics.hpp>


class Object
{
public:
	Object();
	Object(char type);
	sf::Texture& getTexture();
	char getType();
	void loadTexture();

private:
	sf::Texture m_texture;
	char m_type;
};