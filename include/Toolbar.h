#pragma once

#include "Object.h"
#include "vector"

class Toolbar
{
public:
	Toolbar();
	int getSize() const;
	friend std::ostream& operator<<(std::ostream&, const Toolbar&);


private:
	std::vector<Object> m_objects;

};
