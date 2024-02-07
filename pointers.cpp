#include "pointers.h"
#include <iostream>
#define ENDLINE << std::endl;
#define COUT std::cout<<
namespace CPP_Adventures {
	typedef int I;
	void printFromPointer(void* ptr,char type) {
		COUT ptr ENDLINE

			switch (type)
			{
			case 'i':COUT * ((int*)ptr) ENDLINE
				break;
			case 'c':COUT * ((char*)ptr) ENDLINE
				break;
			}
	}
	void pointers::BasePointer()
	{
		I n = 100;
		//std::cout << &n<<std::endl;
		int* ptr = &n;
		//dereferencing the pointer
		//std::cout << *ptr;
		char c = 'a';
		void* cptr = &c;
		//COUT cptr  ENDLINE;

		// void* can be assigned to any type of pointer but cant be dereferenced
		printFromPointer(cptr,'c');
		printFromPointer(ptr,'i');
		system("pause>0");
	}
	void pointers::ArrayPointer()
	{
		int  numbers[4] = { 1,2,3,4 };
		COUT numbers ENDLINE
			COUT& numbers[0] ENDLINE
			COUT* (numbers + 2)ENDLINE
			int size;
		std::cin >> size;
		//int arr[size];
		int* arr = new int[size];

		for (int i = 0; i < size; i++) {
			arr[i] = i + 1;
			COUT arr[i] ENDLINE
		}
		//deallocate the memory
		delete[] arr;
		//removing the pointer
		arr = NULL;
	}
}