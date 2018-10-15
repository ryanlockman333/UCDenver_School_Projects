/*
Ryan Lockman: 101430670
CSCI 2421:001 Fall 2013
hw3.cpp
Description: This program reads a set of integers from a file into
			 a polynomial data class and then performs calculations on the data.
*/

// Headers
#include <iostream>
#include "polynomial.h"
#include "hw3functions.h"

int main() {
	// Declarations
	int choice = 0, poly = 0, pos = 0, coef = 0, n = 0, result = 0;;
	polynomial p1;
	polynomial p2;
	polynomial p3;
	
	std::cout << "Hello, This program reads a set of integers from a file into\n"
				 "a polynomial and allows the user to perform calculations on the data.\n";
	
	// Read Data File
	p1.readFile("pData.txt", 1);
	p2.readFile("pData.txt", 2);
	
	// Loop Program
	do {
		std::cout << "\n\nMENU"
				  << "\n1. Set a Coefficient"
				  << "\n2. Get a Coefficient"
				  << "\n3. Display Polynomials"
				  << "\n4. Add the Polynomials"
				  << "\n5. Multiply the Polynomials"
				  << "\n6. Evaluate a Polynomial(Horner's Rule)"
				  << "\n7. Exit\n"
				  << "\n\nPlease choose: ";
		std::cin  >> choice;
		
		// Process Choice
		switch(choice) {
			case 1:
				std::cout << "\nWhich polynomial would you like to set the coefficient for: ";
				std::cin  >> poly;
				std::cout << "\nWhat position would you like to reset: ";
				std::cin  >> pos;
				std::cout << "\nWhich value would you like to insert: ";
				std::cin  >> coef;
				
				if(poly == 1)
					p1.setCoef(pos, coef);
				else if(poly == 2)
					p2.setCoef(pos, coef);
				break;
			case 2:
				std::cout << "\nWhich polynomial would you like to get the coefficient for: ";
				std::cin  >> poly;
				std::cout << "\nWhat position would you like to get: ";
				std::cin  >> pos;
				
				if(poly == 1)
					std::cout << "\nCoefficient at position " << pos << " = " << p1.getCoef(pos);
				else if(poly == 2)
					std::cout << "\nCoefficient at position " << pos << " = " << p2.getCoef(pos);
				break;
			case 3:
				std::cout << "P1 = " << p1;
				std::cout << "P2 = " << p2;
				break;
			case 4:
				p3 = p1 + p2;
				std::cout << "Added polynomial = " << p3;
				break;
			case 5:
				std::cout << "\nSorry, multiplications isn't finished.\n";
				break;
			case 6:
				std::cout << "\nWhich polynomial would you like to evaluate(Horner's Rule): ";
				std::cin  >> poly;
				std::cout << "\nEnter n: ";
				std::cin  >> n;
				
				if(poly == 1) {
					result = p1.evaluateAt(n);
					std::cout << "Evaluation = " << result << "\n";
				}
				else if(poly == 2) {
					result = p2.evaluateAt(n);
					std::cout << "Evaluation = " << result << "\n";
				}
				break;
			case 7:
				std::cout << "\nGood Bye!";
				break;
		}
		
	}while(choice != 7);

	return 0;	
}
