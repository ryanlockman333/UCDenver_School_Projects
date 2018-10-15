// This program converts cents to dollars and totals sum it
// Ryan Lockman: 101430670

// Headers
#include <iostream>
#include <iomanip>

// Function Prototypes
void normalizeMoney(float& dollars, int cents = 150); 
// This function takes cents as an integer and converts it to dollars
// and cents. The default value for cents is 150 which is converted 
// to 1.50 and stored in dollars

int main() {
	int   cents   = 0;
	float dollars = 0;
 
	std::cout << std::setprecision(2) << std::fixed << std::showpoint;

	cents = 95;
	std::cout << "\n We will now add 95 cents to our dollar total\n\n";

	normalizeMoney(dollars, cents);

	std::cout << "Converting cents to dollars resulted in " << dollars << " dollars\n";
	std::cout << "\n We will now add 193 cents to our dollar total\n\n";

	normalizeMoney(dollars, 193);

	std::cout << "Converting cents to dollars resulted in " << dollars << " dollars\n";
	std::cout << "\n We will now add the default value to our dollar total\n\n";
 
	normalizeMoney(dollars);

	std::cout << "Converting cents to dollars resulted in " << dollars << " dollars\n";
  
	return 0;
}

//  *******************************************************************************
//                               normalizeMoney
//                               
//   task:      This function is given a value in cents.  It will convert cents 
//              to dollars and cents which is stored in a local variable called 
//              total which is sent back to the calling function through the
//              parameter dollars.  It will keep a running total of all the money
//              processed in a local static variable called sum.  
//              
//   data in:   cents which is an integer
//   data out:  dollars  (which alters the corresponding actual parameter)
//
//   *********************************************************************************
void normalizeMoney(float& dollars, int cents) {
	float total = 0;
	static float sum = 0.0;
    
	total   = (float)cents / 100;
	dollars = total;
	sum     = sum + dollars;      			
   
	std::cout << "We have added another $" << dollars << " to our total\n";
    std::cout << "Our sum total so far is  $" << sum << std::endl;

	std::cout << "The value of our local variable total is $" << total << std::endl;
}

/* 
I expect the program to print the following after the first and second iteration through the adding process
	We will now add 95 cents to our dollar total
   We have added another $0.95 to our total
   Our sum total so far is  $0.95
   The value of our local variable total is $0.95
   Converting cents to dollars resulted in 0.95 dollars
   
    We will now add 193 cents to our dollar total
	We have added another $1.93 to our total
	Our sum total so far is  $2.88
	The value of our local variable total is $1.93
	Converting cents to dollars resulted in 1.93 dollars
	
	The total = total + dollars, would induce wrong results so I changed it, otherwise 1st iteration would
	 have it equal $3.00 and 2nd iteration would have it equal $3.86/ its non static local so it wont stay like sum
*/
// sum should be defined as a local static that looks like this, static float sum = 0.0
