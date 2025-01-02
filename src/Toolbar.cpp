#pragma once

#include "Toolbar.h"

Toolbar::Toolbar() 
{
    loadFromFile("Toolbar.txt");
}
//==================================
void Toolbar::loadFromFile(const std::string& filename)
{
    std::ifstream file(filename);

    int i = 0;
    char ch = ' ';

    while (file.get(ch)) 
    {
        if (ch == '\n') 
        {
            continue;
        }
        
        Object obj(ch, i); 
        m_objects.push_back(obj); 
        i++;
    }

    file.close();
}
//=================================
Object& Toolbar::getObject(const int i)  
{
    return m_objects[i];
}
//==================================
int Toolbar::getSize()
{
    return m_objects.size();
}
//==================================
