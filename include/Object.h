#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <ostream>

class Object
{
public:
	Object();
	Object(char type, int i);
	sf::Texture& getTexture();
	void loadTexture(int i);

private:
	sf::Texture m_texture;
	//sf::Sprite m_sprite;
	char m_type;
};