#pragma once

#include "Object.h"
#include "io.h"

class Loc_Object
{
public:
	Loc_Object(Location location, Object* object);
	sf::Texture& getTexture();
	Location getLocation();
	void setLocation(const int x, const int y);

private:
	Location m_location;
	Object* m_object;
};

