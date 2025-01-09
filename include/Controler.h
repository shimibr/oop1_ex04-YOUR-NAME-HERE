#pragma once
#include "Board.h"
#include "Toolbar.h"
#include "LoadFile.h"
#include "io.h"

class Controler
{
public:
    Controler();
    void run();

private:
    void delete_window();
    void fill_from_file();
    void init_Object(Object* object, Location location);
    void loading_window();
	void robot_control(const int row, const int col, Object* Tdelete);
    void oction_save(Object*& object);
	void toolbar_event(sf::RenderWindow& window, Object*& object, Location mouseLoc);
    void board_event(sf::RenderWindow& window, Object* object, Location mouseLoc);


    
    Location m_sizeWindow;
    LoadFile m_loadFile;
    Board m_board;
    Toolbar m_toolbar;
	Location m_robotLocation;
};
