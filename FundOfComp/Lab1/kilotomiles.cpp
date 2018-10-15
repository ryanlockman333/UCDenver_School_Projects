// This program will convert from kilometres to miles.
// Ryan Lockman: 101430670

// Headers
#include <iostream>

// Consts
const float KILO = 0.621;

int main() {
    float input  = 0;
	float mile   = 0;
	float answer = 0;
	
	std::cout << "Please enter a number in kilometres: ";
	std::cin  >> input;
	std::cout << "\nYour number converted to miles is: " << input * KILO << " miles" << std::endl;
	
	return 0;
}

// The program does display the correct output.