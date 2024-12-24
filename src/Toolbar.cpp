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


    int x = 0;
    char ch = ' ';

    // קורא כל תו בנפרד מתוך הקובץ
    while (file.get(ch)) {
        // מתעלמים מתו רווח או תו ריק
        if (ch == ' ' || ch == '\n') {
            continue;
        }

        
        Object obj(x, 0, ch); 
        m_objects.push_back(obj);
        x += 50; 
    }

    file.close();
}

//=================================
const std::vector<Object>& Toolbar::getObjects() const {
    return m_objects;
}
