#pragma once
#include "Toolbar.h"
#include "io.h"

Toolbar::Toolbar() 
    : m_sizeObject(0)
{
    load_from_file("Toolbar.txt");
}
//==================================
void Toolbar::load_from_file(const std::string& filename)
{
    loading_default_buttons();
    std::ifstream file(filename);

    char ch;
    while (file.get(ch))   
        m_objects.push_back(Object(ch));

    file.close();
}
//=================================
void Toolbar::loading_default_buttons()
{
    m_objects.push_back(Object(Entity::FREE_SPASE));
    m_objects.push_back(Object(Entity::CLEAN_BOARD));
    m_objects.push_back(Object(Entity::SAVE));
}
//=================================
Object& Toolbar::get_object(const int i)  
{
    return m_objects[i];
}
//==================================
int Toolbar::get_size()const
{
    return m_objects.size();
}
//==================================
void Toolbar::set_sizeObject(const int sizeWindow)
{
	m_sizeObject = sizeWindow / m_objects.size();
}
//==================================
int Toolbar::get_sizeObject() const
{
    return m_sizeObject;
}
//==================================
