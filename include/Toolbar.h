#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "Object.h"

class Toolbar {
public:
    Toolbar(const std::string& filename);

    const std::vector<Object>& getObjects() const;

private:
    void loadFromFile(const std::string& filename);

    std::vector<Object> m_objects;
};
