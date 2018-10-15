// This program reads monthly sales into a dynamic array to find the
//  sum and average of the sales for that month and year.
// Ryan Lockman: 101430670

// Headers
#include <iostream>

int main() {
	// Declarations
	float *monthlySales = NULL;
	int months = 0;
	float sum = 0, avg = 0;
	
	std::cout << "\nPlease enter in the total months for sale inputs: ";
	std::cin  >> months;

	monthlySales = new float[months];
	
	for(int i = 0; i < months; ++i) {
		std::cout << "Please enter in total sales for month " << i+1 << ": ";
		std::cin  >> monthlySales[i];
	}
	
	for(int i = 0; i < months; ++i)
		sum += monthlySales[i];
		
	avg = sum/months;
	
	std::cout << "\nThe total sales for the year is: $" << sum;
	std::cout << "\nThe average monthly sale is:     $" << avg;

	return 0;
}
