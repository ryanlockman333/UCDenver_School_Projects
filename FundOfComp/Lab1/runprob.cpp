// This program will take a number and divide it by 2.
// Ryan Lockman: 101430670

// Headers
#include <iostream>

int main() {
	float number  = 0;
	int   divider = 2;
	
	std::cout << "Hi there" << std::endl;
	std::cout << "Please input a number and then hit return" << std::endl;
	std::cin  >> number;
	
	number = number / divider;
	
	std::cout << "Half of your number is " << number << std::endl;
	
	return 0;
}

// Output of 9 = 4.5
// Output of 10 = 5
// The outputs are correct.