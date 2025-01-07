#include "LoadFile.h"

#include <iostream>
#include <fstream>

LoadFile::LoadFile()
    : is_file(true), m_loc_robot{ 0,0 }
{
	m_i = 0;
	m_j = 0;
    fill_data();
    m_size_col = col_size();
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
//=================================
void LoadFile::update_data()
{
	std::ofstream file("Board.txt");
	for (int i = 0; i < m_data.size(); i++)
	{
		file << m_data[i] << std::endl;
	}
	file.close();
    
}
//======================================
Location LoadFile::get_loc_robot()
{
    return m_loc_robot;
}
//===================================
bool LoadFile::check_if_robot(Location loc)
{
    return m_data[loc.row][loc.col] == '/';
}
//==============================
int LoadFile::col_size()
{
    int size = 0;
    for (int i = 0; i < m_data.size(); i++)
    {
        if (m_data[i].size() > size)
            size = m_data[i].size();
    }
    return size;
}
//==================================
bool LoadFile::get_from_file(Char_Location& chLoc)
{
    for (m_i = m_i; m_i < m_data.size(); m_i++)
    {
		for (m_j = m_j; m_j < m_data[m_i].size(); m_j++)
		{
			if (m_data[m_i][m_j] != ' ')
			{
                if (m_data[m_i][m_j] == '/')
                    m_loc_robot = Location(m_i+1, m_j);

				chLoc.location = Location(m_i,m_j);
				chLoc.type = m_data[m_i][m_j];
                m_j++;
				return true;
			}
		}
        m_j = 0;
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
    return m_size_col;
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
