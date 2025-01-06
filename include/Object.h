#pragma once

#include <SFML/Graphics.hpp>

//#include <vector>
//#include <string>
//#include <fstream>
//#include <iostream>
//#include <ostream>

class Object
{
public:
	Object();
	Object(char type, int i);
	sf::Texture& getTexture();
	char getType();
	void loadTexture(int i);

private:
	sf::Texture m_texture;
	char m_type;
};