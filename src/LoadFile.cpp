#include "LoadFile.h"

#include <iostream>
#include <fstream>

LoadFile::LoadFile()
	:  is_file(true)
{
	m_i = 0;
	m_j = 0;    
    fill_data();
}
//=================================
void LoadFile::fill_data()
{
    std::ifstream file("Board.txt");

    if (!file)
    {
		is_file = false;
        return;
    }
    std::string line;
    while (std::getline(file, line))
    {
        m_data.push_back(line);
    }
}
//==================================
bool LoadFile::get_from_file(Char_Location& chLoc)
{
    for (int i = (m_i+1); i < get_row_size(); i++)
    {
		for (int j = (m_j+1); j < get_col_size(); j++)
		{
			if (m_data[i][j] != ' ')
			{
				chLoc.location = Location(i,j);
				chLoc.type = m_data[i][j];
				m_i = i;
				m_j = j;
				return true;
			}
		}

    }

    return false;
}
//================================
void LoadFile::set_to_file(Char_Location chLoc)
{
	m_data[chLoc.location.row][chLoc.location.col] = chLoc.type;
}
//==================================
int LoadFile::get_row_size()
{
    return m_data.size();
}
//===================================
int LoadFile::get_col_size()
{
    int size = 0;
    for (int i = 0; i < m_data.size(); i++)
    {
        if (m_data[i].size() > size)
            size = m_data[i].size();
    }
    return size-20;
}
//==================================
void LoadFile::set_row_size()
{

}
//==================================
void LoadFile::set_col_size()
{
}
//==================================
bool LoadFile::get_is_file()
{

	return is_file;
}
//==================================
