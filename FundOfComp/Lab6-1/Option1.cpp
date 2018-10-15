/*
This Program will prompt the user to enter two numbers, then call
a function named swap to switch the values and return them to main.
Ryan Lockman: 101430670
*/

// Headers
#include <iostream>

// Function Prototypes
void swap(int &number1, int &number2);
// Pre-Condition:  number 1 and 2 must be of type int
// Post-Condition: number 1 and 2 are swapped via pass by reference

int main() {
	// Declarations
	int first = 0, second = 0;

	// Input
	std::cout << "This program swaps a users two inputs.\n\n";
	std::cout << "\nPlease enter in your first number:  ";
	std::cin  >> first;
	std::cout << "\nPlease enter in your second number: ";
	std::cin  >> second;
	std::cout << "\nYou entered in first = " << first << " and second = " << second;
	
	// Swap
	swap(first, second);
	
	// Output
	std::cout << "\n\nAfter the call to swap"
			  << "\nfirst = " << first << " and " << "second = " << second;
	
	return 0;
}

void swap(int &number1, int &number2) {
	int tmpNum2 = number2;
	number2     = number1;
	number1     = tmpNum2;
}

// The values must be pass by reference because our function has no return type,
//  because it is a void function.
