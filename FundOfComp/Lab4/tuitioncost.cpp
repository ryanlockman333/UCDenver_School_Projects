// This program calculates a student's total tuition cost for The University of Guiness.
// Ryan Lockman: 101430670

// Headers
#include <iostream>

int main() {
	char   tuition;
	char   rAndB;
	double cost = 0;
	
	// Input
	std::cout << "Please input 'I' if you are in-state or 'O' if you are out-of-state: ";
	std::cin  >> tuition;
	std::cout << "\nPlease input 'Y' if you require room and board and 'N' if you do not: ";
	std::cin  >> rAndB;

	// Calculate tuition
	if(tuition == 'I' || tuition == 'i')
		cost = 3000;
	else if(tuition == 'O' || tuition == 'o')
		cost = 4500;
	
	// Calculate room and board
	if(rAndB == 'Y' || rAndB == 'y')
		if(tuition == 'I' || tuition == 'i')
			cost = cost + 2500;
		else if(tuition == 'O' || tuition == 'o')
			cost = cost + 3500;
	else if(rAndB == 'N' || rAndB == 'n')
		cost = cost;

	// Output
	std::cout << "\n\nYour total bill for this semester is: $" << cost;

	return 0;
}
