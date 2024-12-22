#pragma once

#include "Location.h"
#include <ostream>

class Object
{
public:
	Object();
	Object(int x, int y, char type);
	friend std::ostream& operator<<(std::ostream&, const Object&);

private:
	Location m_location;
	char m_type;


};