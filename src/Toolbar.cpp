#pragma once

#include "Toolbar.h"

Toolbar::Toolbar(const std::string& filename) 
{
    loadFromFile(filename);
}
//==================================
void Toolbar::loadFromFile(const std::string& filename)
{
    std::ifstream file(filename);

    int y = 0;
    char ch = ' ';

    while (file.get(ch)) 
    {
        if (ch == '\n') 
        {
            continue;
        }
        
        Object obj(0, y, ch); 
        m_objects.push_back(obj);
        y += 50; 
    }

    file.close();
}
//=================================
const std::vector<Object>& Toolbar::getObjects() const 
{
    return m_objects;
}
