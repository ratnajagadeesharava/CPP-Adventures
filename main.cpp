#include<iostream>
#include "lambdas.h"
#include <thread>
#include "threads.h"
using namespace CPP_Adventures;
void main() {
	std::cout << "Hello World" << std::endl;
	//Threads::call_threads(10);
	//Threads::MakeForecasts();
	Threads::RunMutex();
	lambdas lam;
}