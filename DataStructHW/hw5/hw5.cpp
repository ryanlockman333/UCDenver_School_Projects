/*
Ryan Lockman: 101430670
CSCI 2421:001 Fall 2013
hw5.cpp - Driver File
Project:
Description: This program reads data in from a file and stores them in 3 Set
			 data structures to perform Union, Intersection, and Difference
			 operations on them.
*/

// Headers
#include <iostream>
#include <cstdlib>
#include <string>
#include "set.h"
#include "hw5functions.h"

int main(int argc, char *argv[]) {
	// Declarations
	Set<int> A, B, C;
	
	// Read File
	if(argc != 2) {
		std::cout << "\nError, type file path in as second argument in terminal.\n";
		return 1;
	}
	else {
		std::cout << "\nThe number of arguments: " << argc
				  << "\nThe name of the file:    " << argv[0];
		readFile(argv[1], A, B, C);
	}
	
	// Output Description
	std::cout << "\n\nThis program reads data in from a file and stores them in 3 Set"
			  << "\ndata structures to perform Union, Intersection, and Difference"
			  << "\noperations on them.\n";
	
	// Calculations
	std::cout << "\nA = {" << A;
	std::cout << "}";
	std::cout << "\nB = {" << B;
	std::cout << "}";
	std::cout << "\nC = {" << C;
	std::cout << "}";
	
	std::cout << "\n\nA & (B + C)        = {";
	Set<int> calc1 = A & (B + C);
	std::cout << calc1;
	std::cout << "}";
	
	std::cout << "\n(A + B) - C        = {";
	Set<int> calc2 = (A + B) - C;
	std::cout << calc2;
	std::cout << "}";
	
	std::cout << "\n(A & B) + (B & C)  = {";
	Set<int> calc3 = (A & B) + (B & C);
	std::cout << calc3;
	std::cout << "}";
	
	std::cout << "\n(A - B) + (C - A)  = {";
	Set<int> calc4 = (A - B) + (C - A);
	std::cout << calc4;
	std::cout << "}";
	
	std::cout << "\n(A & B) == (B - C) = ";
	if((A & B) == (B - C))
		std::cout << std::boolalpha << true;
	else
		std::cout << std::boolalpha << false;
	std::cout << std::endl;
	
	return 0;
}
