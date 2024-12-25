#pragma once

#include "Loc_Object.h"

Loc_Object::Loc_Object(int x, int y, Object* object)
	:m_location{x,y}, m_object(object) { }
