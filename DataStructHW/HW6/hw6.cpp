/*
Ryan Lockman: 101430670
CSCI 2421:001 Fall 2013
hw6.cpp - Driver File
Project: Recursive Sort
Description: This program recursively sorts an array of n size and also
			 recursively prints a star pattern.
*/

// Headers
#include <iostream>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include "hw6functions.h"

int main(int argc, char *argv[]) {
	// Check Arguments
	if(argc < 5) {
		std::cout << "\nError starting program, need 5 arguments.\n"
				  << "Example ./program 1000 25 99 15\n";
		return 1;
	}
	else
		std::cout << "\nThe number of arguments: " << argc
				  << "\nThe name of the file:    " << argv[0];
	
	// Declarations
	int array[atoi(argv[1])];

	// Output
	fillArray(array, atoi(argv[1]), atoi(argv[2]), atoi(argv[3]));
	std::cout << "\n\nUnsorted Array";
	printArray(array, atoi(argv[1]));
	std::cout << "\nSorted Array";
	recursiveSort(array, atoi(argv[1]));
	printArray(array, atoi(argv[1]));
	std::cout << "\nPattern";
	recurPatternPrint(atoi(argv[4]));
	
	return 0;
}
