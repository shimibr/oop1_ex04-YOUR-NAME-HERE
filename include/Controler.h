#pragma once
#include "Board.h"
#include "Toolbar.h"

class Controler
{
public:
    Controler();
    void run();

private:
    void fill_from_file(sf::RenderWindow& window);

    const int m_sizeObject = 50;
    Board m_board;
    Toolbar m_toolbar;
};
