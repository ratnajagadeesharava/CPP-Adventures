#include "SmartPointers.h"
#include<iostream>
SmartPointers::SmartPointers()
{
	std::cout << "Constructor invoked" << std::endl;
}

SmartPointers::~SmartPointers()
{
	std::cout << "Destructor invoked" << std::endl;
}
