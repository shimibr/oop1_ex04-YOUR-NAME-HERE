#pragma once

#include "Object.h"

Object::Object()
	:Object(' ',0) { }
//============================
Object::Object(char type, int i)
	:m_type{type}
{
	loadTexture(i);
}
//============================
sf::Texture& Object::getTexture()
{ 
	return m_texture;
}
//=============================
char Object::getType()
{
	return m_type;
}
//============================
void Object::loadTexture(int i)
{
 	if(m_type == '/')
		m_texture.loadFromFile("robot.png");
	else if(m_type == ' ')
		m_texture.loadFromFile("delete.png");
	else if (m_type == '!')
		m_texture.loadFromFile("guard.png");
	else if (m_type == 'D')
		m_texture.loadFromFile("door.png");
	else if (m_type == '@')
		m_texture.loadFromFile("stone.png");
	else if (m_type == '#')
		m_texture.loadFromFile("wall.png");
	
	//m_sprite.setPosition(i*50,0);
}
