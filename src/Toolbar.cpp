#include "Toolbar.h"

Toolbar::Toolbar()
{
	m_objects.push_back(Object(0, 0, ' '));
	m_objects.push_back(Object(0, 0, '/'));
	m_objects.push_back(Object(0, 0, '!'));
	m_objects.push_back(Object(0, 0, 'D'));
	m_objects.push_back(Object(0, 0, '#'));
	m_objects.push_back(Object(0, 0, '@'));
}
//==========================
int Toolbar::getSize() const
{
	return m_objects.size();
}
//==========================

std::ostream& operator<<(std::ostream& os, const Toolbar& other)
{
	for (int i = 0; i < other.m_objects.size(); ++i)
	{
		os << other.m_objects[i];
	}
	return os << '\n';
}