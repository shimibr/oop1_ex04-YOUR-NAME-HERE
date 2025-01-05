#pragma once

#include "Object.h"
#include "Location.h"

class Loc_Object
{
public:
	Loc_Object(int x, int y, Object* object);
	sf::Texture& getTexture();
	Location getLocation();
	void setLocation(const int x, const int y);

private:
	Location m_location;
	Object* m_object;
};

