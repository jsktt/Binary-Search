////////////////////////////////////////////////////////
// ECE 2574, Homework 3
// File name:   hw3_main.cpp
// Description: STARTER CODE
// Date:        11/11/2023
//
#include <iostream>
#include <string>
#include "hw3_function.h"

extern int funcCallCounter;

int main() {
	
	std::vector<std::string> pSet;
	std::string bSet="ab";

	powerSet(pSet, bSet);  //make sure you can call the powerSet function like this.

	std::cout << "Debug...\n";
	std::getchar();
	return 0;

}