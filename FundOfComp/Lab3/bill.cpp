// This program will read in the quantity of a particular item and its price.
// It will then print out the total price.
// The input will come from the keyboard and the output will go to
// the screen.
// Ryan Lockman: 101430670

// Headers
#include <iostream>
#include <string>
#include <iomanip>

int main() {
	int   quantity  = 0;		// contains the amount of items purchased
	float itemPrice = 0;		// contains the price of each item
	float totalBill = 0;		// contains the total bill.  
	std::string name;

	std::cout << std::setprecision(4) << std::fixed << std::showpoint;  //formatted output
	std::cout << "Please input the name of the item: ";
	std::getline(std::cin, name);
	std::cout << "Please input the number of items bought: ";   
	std::cin  >> quantity;
	std::cout << "Please input the price of each item: ";
	std::cin  >> itemPrice;

	totalBill = quantity*itemPrice;
	
	std::cout << "\nThe item you bought is: " << name;
	std::cout << "\nThe total bill = $" << totalBill;

	return 0;
}

// When taking off the fixed format the output is changed to 2.4e+02 instead of 241.56.
// When using fixed floating point values are written using fixed point notation, (exact digits represented
// in the decimal part as declared by the setprecision attribute).

// When changing setprecision to 4 it changes the itemPrice to 
// The setprecision attribute specifies the number of decimal digits to display.
