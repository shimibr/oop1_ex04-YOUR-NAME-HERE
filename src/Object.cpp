#pragma once

#include "Object.h"

Object::Object()
	:Object(0,0, ' ') { }
//============================
Object::Object(int x, int y, char type)
	:m_location(x, y), m_type(type)
{
	loadTexture();
}
//============================
const sf::Sprite& Object::getSprite() const
{
	return m_sprite;
}
//============================
void Object::loadTexture()
{

 	if(m_type == '/')
		m_texture.loadFromFile("../resources/robot.png");
	else if (m_type == '!')
		m_texture.loadFromFile("../resources/guard.png");
	else if (m_type == 'D')
		m_texture.loadFromFile("../resources/door.png");
	else if (m_type == '@')
		m_texture.loadFromFile("../resources/stone.png");
	else if (m_type == '#')
		m_texture.loadFromFile("../resources/wall.png");

	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(static_cast<float>(m_location.col), static_cast<float>(m_location.row));
}
