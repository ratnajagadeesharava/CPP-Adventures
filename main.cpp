#include<iostream>
#include "lambdas.h"
#include "pointers.h";
#include <thread>
#include "threads.h"
#include "Human.h"
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
	Human human("Jagadeesh", 24);
	Human* h2 = new Human("RJ", 25);
	ChangeHuman(&human);
	ChangeHuman(h2);
	ChangeHumanByValue(human);
	ChangeHumanByValue(*h2);
	COUT << human.name <<ENDLINE
	COUT << h2->name << ENDLINE
		
	lambdas lam;
}