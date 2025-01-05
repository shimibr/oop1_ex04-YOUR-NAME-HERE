#pragma once

#include "Loc_Object.h"

Loc_Object::Loc_Object(int x, int y, Object* object)
	:m_location{x,y}, m_object(object) { }
//==================================
sf::Texture& Loc_Object::getTexture()
{
	return m_object->getTexture();
}
//=========================================
Location Loc_Object::getLocation()
{
	return m_location;
}
//================================
void Loc_Object::setLocation(const int x, const int y)
{
	m_location.row = y;
	m_location.col = x;
}
