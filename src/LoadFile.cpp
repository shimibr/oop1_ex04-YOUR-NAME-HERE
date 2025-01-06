#include "LoadFile.h"

#include <iostream>
#include <fstream>

LoadFile::LoadFile()
{
}
//==================================
std::vector<Object> LoadFile::getItems()
{
        std::string fileName = "Board.txt";

        std::ifstream file(fileName);

        if (!file.is_open()) 
        {
            std::cout << "!!!!!!!!!!!!!!";
        }

        char ch;
        int x = 0;
        int y = 0;
        while (file.get(ch)) 
        {
            if (ch == '\n')
            {
                y++;
                x = 0;
            }
            else
            m_Objects.push_back(Object(ch, x));
        }

        file.close();
        for(int i = 0; i < m_Objects.size(); i++)
        std::cout << m_Objects[i].getType();

    return m_Objects;
}
