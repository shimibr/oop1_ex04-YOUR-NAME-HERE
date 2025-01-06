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
    void fill_from_file();
    void init_Object(Object* object,Location location);
    const int m_sizeObject = 50;
    LoadFile m_loadFile;
    Board m_board;
    Toolbar m_toolbar;
};
