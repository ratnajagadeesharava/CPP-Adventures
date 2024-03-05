#include "Human.h"
namespace CPP_Adventures {
	Human::Human(std::string n, int a):name(n),age(a)
	{
	}
	void Human::introduce()
	{
		COUT << "My Name  is " << name << " and my age is " << age << ENDLINE
	}
	
}