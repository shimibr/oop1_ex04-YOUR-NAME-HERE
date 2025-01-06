#pragma once
#include "Object.h"
#include <vector>
#include <string>
#include <fstream>

class Toolbar 
{
public:
    Toolbar();
    Object& getObject(const int i) ;
    int getSize();
    

private:
    void loadFromFile(const std::string& filename);

    std::vector<Object> m_objects;
};
