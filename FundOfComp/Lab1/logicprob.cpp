// This program takes two values from the user and then swaps them
// before printing the values.  The user will be prompted to enter
// both numbers.
// Ryan Lockman: 101430670

// Headers
#include <iostream>

int main() {
	float firstNumber  = 0;
	float secondNumber = 0;
	float tempNumber   = 0;
	
	// Prompt user to enter the first number.	
	std::cout << "Enter the first number" << std::endl;
	std::cout << "Then hit enter" 		  << std::endl;
	std::cin  >> firstNumber;
	
	// Prompt user to enter the second number.
	std::cout << "Enter the second number" << std::endl;
	std::cout << "Then hit enter"          << std::endl;
	std::cin  >> secondNumber;
	
	// Echo print the input.
	std::cout << std::endl << "You input the numbers as " << firstNumber
		      << " and "   << secondNumber << std::endl;
	
    // Now we will swap the values.
	tempNumber   = firstNumber;
	firstNumber  = secondNumber;
    secondNumber = tempNumber;
    
	// Output the values.
	std::cout << "After swapping, the values of the two numbers are "
	          << firstNumber << " and " << secondNumber << std::endl;
	
	return 0;
}

// When ran, the first thing printed is our first cout statement for entering our first number.