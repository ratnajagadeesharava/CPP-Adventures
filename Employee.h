#pragma once
#include "Human.h"
namespace CPP_Adventures {
	class Employee:public Human
	{
	public:
		std::string department;
		Employee(std::string n,int a,std::string d);
		void introduce() override;
	};
}
