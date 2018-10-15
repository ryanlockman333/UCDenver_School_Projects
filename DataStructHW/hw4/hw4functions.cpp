/*
Ryan Lockman: 101430670
CSCI 2421:001 Fall 2013
hw4functions.cpp
Description: Global function definitions.
*/

// Headers
#include <iostream>
#include <fstream>
#include "hw4functions.h"

// Global Functions
void readFile(const std::string fileName, Bag &nounBag, Bag &verbBag) {
	std::string str;
	std::ifstream inFile(fileName.c_str());
	if(!inFile) {
		std::cout << "\nError opening file for reading.\n";
		return;
	}
	
	while(inFile.good())
		if(inFile.peek() == '\n' || inFile.peek() == '\r')
			while(inFile >> str)
				verbBag.insert(str);
		else {
			inFile >> str;
			nounBag.insert(str);
		}
	inFile.close();
}

std::string grabAdverb(std::string adverb[], int length) {	
	int i = (rand() % length);
	return adverb[i];
}

std::string grabPrep(std::string prep[], int length) {	
	int i = (rand() % length);
	return prep[i];
}
