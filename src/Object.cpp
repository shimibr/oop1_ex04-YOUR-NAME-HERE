#include "Object.h"

Object::Object()
	:Object(0,0, ' ') { }

Object::Object(int x, int y, char type)
	:m_location(x, y), m_type(type) { }

//==========================
std::ostream& operator<<(std::ostream& os, const Object& other)
{
    os << other.m_type;
    
	return os << '\n';
}

