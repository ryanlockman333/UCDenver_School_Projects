// This program demonstrates a compile error.
// Ryan Lockman: 101430670

// Headers
#include <iostream>

int main() {
	int   number = 0;
	float total  = 0;
	
	std::cout << "Today is a great day for Lab";
	std::cout << std::endl << "Let's start off by typing a number of your choice" << std::endl;
	std::cin  >> number;
	
	total = number * 2;
	std::cout << total << " is twice the number you typed" << std::endl;
	
	return 0;
}

// Output for 9 = 18
// Output for 10 = 20
// The outputs are correct.