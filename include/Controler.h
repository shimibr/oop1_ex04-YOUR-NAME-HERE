#pragma once
#include "Board.h"
#include "Toolbar.h"
#include "LoadFile.h"


class Controler
{
public:
    Controler();
    void run();

private:
    void delitWindow();
    void fill_from_file();
    void init_Object(Object* object, Location location);
    void loading_window(int &i, int &j);
	void robot_control(const int row, const int col, Object& Tdelete);

    bool m_delitWindow;
    LoadFile m_loadFile;
    Board m_board;
    Toolbar m_toolbar;
	Location m_robotLocation;
};
