#pragma once

#include "Object.h"
#include "io.h"

Object::Object()
	:Object(Entity::FREE_SPASE) { }
//============================
Object::Object(char type)
	:m_type{type}
{
	loadTexture();
}
//============================
sf::Texture& Object::getTexture()
{ 
	return m_texture;
}
//=============================
char Object::getType()const
{
	return m_type;
}
//============================
void Object::loadTexture()
{
 	if(m_type == Entity::ROBOT)
		m_texture.loadFromFile("robot.png");
	else if(m_type == Entity::FREE_SPASE)
		m_texture.loadFromFile("delete.png");
	else if (m_type == Entity::GUARD)
		m_texture.loadFromFile("guard.png");
	else if (m_type == Entity::DOOR)
		m_texture.loadFromFile("door.png");
	else if (m_type == Entity::STONE)
		m_texture.loadFromFile("stone.png");
	else if (m_type == Entity::WALL_OR_EDGE)
		m_texture.loadFromFile("wall.png");
	else if (m_type == Entity::SAVE)
		m_texture.loadFromFile("save.png");
	else if (m_type == Entity::CLEAN_BOARD)
		m_texture.loadFromFile("reset.png");

}
