#pragma once

namespace Entity
{
	const int SIZE_PIXEL = 50;
	constexpr char ROBOT = '/';
	constexpr char STONE = '@';
	constexpr char GUARD = '!';
	constexpr char WALL_OR_EDGE = '#';
	constexpr char DOOR = 'D';
	constexpr char FREE_SPASE = ' ';
	constexpr char SAVE = 'S';
	constexpr char CLEAN_BOARD = 'C';

}
//=====================================
struct Location
{
	int row;
	int col;
};
//=====================================
struct Char_Location
{
	Location location;
	char type;
};

struct Loc_Object 
{
	Location location;
	Object* object;


};