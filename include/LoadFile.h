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
	void fill_data();
	bool get_from_file(Char_Location& chLoc);
	void set_to_file(Char_Location chLoc);
	int get_row_size();
	int get_col_size();
	void set_row_size();
	void set_col_size();
	bool get_is_file(); 

private:
	int m_i, m_j;
	bool is_file;
	std::vector<std::string> m_data;

};
