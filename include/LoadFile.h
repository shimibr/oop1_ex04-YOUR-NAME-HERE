#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "Object.h"
#include "Location.h"

class LoadFile
{
public:
	LoadFile();
	bool get_from_file(Char_Location& chLoc);
	void set_to_file(Char_Location chLoc);
	int get_row_size();
	int get_col_size();
	void set_row_size();
	void set_col_size();
	bool get_is_file();  
	void update_data();
	Location get_loc_robot();
	bool check_if_robot(Location loc);


private:
	void fill_data();
	int col_size();

	int m_i, m_j;
	Location m_loc_robot;
	bool is_file;
	int m_size_col;
	std::vector<std::string> m_data;

};
