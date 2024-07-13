#include<iostream>
#include<fstream>
#include<thread>

#include "lambdas.h"
#include "pointers.h";
#include "threads.h"
#include "Human.h"
#include "SmartPointers.h"

#include <Eigen/Dense>
#include <Eigen/Sparse>
#include "Solution.hpp"



using namespace Eigen;
using namespace std;
using namespace CPP_Adventures;

void ChangeHuman(Human *h1) {
	COUT << h1->name << ENDLINE
		h1->name = "ARJ";

}
void writeToTextFile(string fileName) {
	fstream myFile;
	myFile.open("random.txt", ios::app);
	if (myFile.is_open()) {
		myFile<< "hello file" << endl;
		myFile << "this is comming from the program" << endl;
		myFile.close();
		cout << "File Closed Succesfully" << endl;
	}
}
#define A -B
#define B -C
#define C 5
void readTextFile(string fileName) {
	fstream myFile;
	myFile.open(fileName, ios::in);
	string line;
	while (getline(myFile, line)) {
		cout << line << endl;
	}
	myFile.close();
	
}
void ChangeHumanByValue(Human human) {
	COUT << human.name << ENDLINE
	human.name = "ARJ2";

}
void setZeroes(vector<vector<int>>& matrix) {
	int m = matrix.size();
	int n = matrix[0].size();

	int r = 0;
	int c = 0;
	if (n == 0)
		return;
	for (int i = 0; i < m; i++) {


		for (int j = 0; j < n; j++) {
			if (matrix[i][j] == 0) {
				int rd = pow(2, i);
				int cd = pow(2, j);
				r = r | rd;
				c = c | cd;
			}
		}
	}
	//cout << r << " " << c << "  " << endl;
	bool rowflag = false;
	bool colflag = false;
	for (int i = 0; i < m; i++) {
		
		int k = c;
		for (int j = 0; j < n; j++) {
			
			
			if (k % 2 == 1|| r%2 ==1) {
				matrix[i][j] = 0;
			}
			k = k << 1;
		}
		r = r << 1;
	}


}


int const s = 123;
#define MAX 1000

struct s1 {
	int a = 22;
};

void fun() {
	static int i = 5;
	if (--i) {
		cout << i << endl;
		fun();
	}
}

struct sample {
	int a;
}s1;
enum color {
	black ,
	red,
	blue,
	green

};

template <typename T>
T sum(T a, T b ,int c) {
	return a + b+c;
}
const int j = 9;
void main() {
	CPP_adventures::Solution sol;
	sol.callMethod();
}

