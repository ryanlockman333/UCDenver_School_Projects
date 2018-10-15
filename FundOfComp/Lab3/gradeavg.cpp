// This program calculates the average of the three grades entered.
// Ryan Lockman: 101430670

// Headers
#include <iostream>
#include <iomanip>

int main() {
	float grade1 = 0, grade2 = 0, grade3 = 0;
	float avg    = 0;
	
	std::cout << "Please input the first grade:  ";
	std::cin  >> grade1;
	std::cout << "\nPlease input the second grade: ";
	std::cin  >> grade2;
	std::cout << "\nPlease input the third grade:  ";
	std::cin  >> grade3;
	
	avg = (grade1 + grade2 + grade3) / 3;
	
	std::cout << std::setprecision(2) << std::fixed << std::showpoint;
	std::cout << "\n\nThe average of the three grades is: " << avg << "%";

	return 0;
}
