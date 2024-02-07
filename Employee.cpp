#include "Employee.h"
namespace CPP_Adventures {
	Employee::Employee(std::string n, int a, std::string d):Human(n,a),department(d)
	{
	}
	void Employee::introduce()
	{
		Human::introduce();
		COUT << "Override success"<<ENDLINE
	}
}