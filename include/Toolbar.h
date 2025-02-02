#pragma once
#include "Object.h"
#include <vector>
#include <string>
#include <fstream>

class Toolbar 
{
public:
    Toolbar();
    Object& get_object(const int i) ;
    int get_size()const;
    void set_sizeObject(const int sizeWindow);
	int get_sizeObject()const;

private:
    void load_from_file(const std::string& filename);
    void loading_default_buttons();

    std::vector<Object> m_objects;
    int m_sizeObject;
};
