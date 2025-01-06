#pragma once

struct Location
{
    int row;
    int col;
};

struct Char_Location
{
    Location location;
    char type;
};