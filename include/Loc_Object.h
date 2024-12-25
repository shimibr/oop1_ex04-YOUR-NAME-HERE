#pragma once

#include "Object.h"
#include "Location.h"

class Loc_Object
{
public:
	Loc_Object(int x, int y, Object* object);

private:
	Location m_location;
	Object* m_object;
};

