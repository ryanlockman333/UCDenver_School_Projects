// This program will read in the qunatity of a particular item and its price.
// It will then print out the total price.
// The input will come from a data file and the output will go to
// an output file.
// Ryan Lockman: 101430670

// Headers
#include <iostream>
#include <fstream>
#include <iomanip>

int main() {
   	std::ifstream dataIn;	    // defines an input stream for a data file
	std::ofstream dataOut;	    // defines an output stream for an output file
	int quantity    = 0;		// contains the amount of items purchased
	float itemPrice = 0;		// contains the price of each item
	float totalBill = 0;		// contains the total bill.  The price of all items

	dataIn.open("transaction.dat");  // This opens the file.
	if(!dataIn)
		std::cout << "\nError opening data for reading.\n";
	dataOut.open("bill.dat");

	// Fill in the appropriate code in the blank below
	std::cout << std::setprecision(2) << std::fixed << std::showpoint;  // formatted output

	// Fill in the input statement that brings in the 
	// quantity and price of the item.
	while(dataIn.good())
		dataIn >> quantity >> itemPrice;
	dataIn.close();
	
	// Fill in the assignment statement that determines the totalBill.
	totalBill = itemPrice*quantity;

	dataOut << totalBill;
	dataOut.close();
	
	// Fill in the output statement that prints the total bill, with a label,
	// to an output.
	std::cout << "\nThe total bill equals: $" << totalBill;
	
	return 0;
}
