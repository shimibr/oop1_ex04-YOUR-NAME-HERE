#pragma once

#include "Object.h"

class Toolbar 
{
public:
    Toolbar();
    const std::vector<Object>& getObjects() const;
    int getSize();
    Object& operator()(const int i);

private:
    void loadFromFile(const std::string& filename);

    std::vector<Object> m_objects;
};
