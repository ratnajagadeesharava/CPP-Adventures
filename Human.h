#pragma once
#include<iostream>
#define COUT std::cout
#define ENDLINE std::endl;

#include <string>
namespace CPP_Adventures {
	class Human
	{
	
		
	public:
		std::string name;
		int age;
		Human(std::string  n, int a);

		virtual void introduce();

	
	};
}
