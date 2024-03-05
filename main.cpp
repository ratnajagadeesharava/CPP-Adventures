#include<iostream>
#include "lambdas.h"
#include "pointers.h";
#include <thread>
#include "threads.h"
#include "Human.h"
#include "SmartPointers.h"
using namespace std;
using namespace CPP_Adventures;

void ChangeHuman(Human *h1) {
	COUT << h1->name << ENDLINE
		h1->name = "ARJ";

}

void ChangeHumanByValue(Human human) {
	COUT << human.name << ENDLINE
	human.name = "ARJ2";

}


void main() {
	std::cout << "Hello World" << std::endl;
	//Threads::call_threads(10);
	//Threads::MakeForecasts();
	//Threads::RunMutex();
	//pointers::BasePointer();
	//pointers::ArrayPointer();
	/*Human human("Jagadeesh", 24);
	Human* h2 = new Human("RJ", 25);
	ChangeHuman(&human);
	ChangeHuman(h2);
	ChangeHumanByValue(human);
	ChangeHumanByValue(*h2);
	COUT << human.name <<ENDLINE
	COUT << h2->name << ENDLINE
		*/
	{
		//unique_ptr allocates and deallocates memory
		unique_ptr<SmartPointers> uptr1 = make_unique<SmartPointers>();
	}

	shared_ptr<SmartPointers> sharedPtr1 = make_shared<SmartPointers>();
	{
		shared_ptr<SmartPointers> sharedPtr2 = sharedPtr1;
		cout << "Shared Count In Scope " << sharedPtr1.use_count() << endl;
	}
	cout << "Shared Count  " << sharedPtr1.use_count()<<endl;
	cout << "WeakPointer Count  "  << endl;
	weak_ptr<SmartPointers> weakPtr1;
	{
		shared_ptr<SmartPointers> sharedPtr3 = make_shared<SmartPointers>();
		weakPtr1 = sharedPtr3;
	}
	lambdas lam;
}