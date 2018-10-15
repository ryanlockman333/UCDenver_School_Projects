// This program will bring in two prices and two quantities of items 
// from the keyboard and print those numbers in a formatted chart.
// Ryan Lockman: 101430670

// Headers
#include <iostream>
#include <iomanip>    // Fill in the code to bring in the library for 
                      // formatted output.

int main() {
	float price1    = 0, price2    = 0;	  // The price of 2 items
	int   quantity1 = 0, quantity2 = 0;   // The quantity of 2 items

	std::cout << std::setprecision(2) << std::fixed << std::showpoint;
	std::cout << "Please input the price and quantity of the first item(separated by a space): ";
	std::cin  >> price1 >> quantity1;
	std::cout << "Please enter in the price and quantity of the second item(separated by a space): ";
	std::cin  >> price2 >> quantity2;
	std::cout << "\n\n";
	std::cout << std::setw(15) << "PRICE" << std::setw(12) << "QUANTITY" << std::endl;
	std::cout << std::setw(15) << price1  << std::setw(12) << quantity1  << std::endl;
	std::cout << std::setw(15) << price2  << std::setw(12) << quantity2  << std::endl;
	
	return 0;
}
