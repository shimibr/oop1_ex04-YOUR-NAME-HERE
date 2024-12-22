#include "Toolbar.h"
#include <iostream>



int main()
{

	Toolbar t1;
	for (int i = 0; i < t1.getSize(); i++)
		std::cout << t1;
}
