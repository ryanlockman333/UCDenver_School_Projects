// This program takes two numbers (pay rate & hours)
// and multiplies them to get grosspay    
// it then calculates net pay by subtracting 15%
// Ryan Lockman:: 101430670

// Headers
#include <iostream>
#include <iomanip>

//Function Prototypes
void printDescription(); 
void computePaycheck(float, int, float, float); 

int main() {
	// Declarations
	float payRate  = 0;
	float grossPay = 0;
	float netPay   = 0;
	int   hours    = 0;
	
	std::cout << std::setprecision(2) << std::fixed;
	std::cout << "Welcome to the Pay Roll Program\n";
	
	printDescription();                                // Call to Description function
	
	std::cout << "Please input the pay per hour\n";
	std::cin  >> payRate;
	std::cout << std::endl << "Please input the number of hours worked\n";
	std::cin  >> hours;
	std::cout << std::endl << std::endl;
	
	computePaycheck(payRate, hours, grossPay, netPay); // Call to Paycheck function
	
	std::cout << "\nWe hoped you enjoyed this program\n";
	
	return 0;
}

//   ********************************************************************
//                         printDescription
//   
//   task:     This function prints a program description
//   data in:  none
//   data out: none
//
//   ********************************************************************
void printDescription() {
    std::cout << "************************************************\n\n";
    std::cout << "This program takes two numbers (pay rate & hours)\n";
	std::cout << "and  multiplies them to get gross pay \n\n";   
    std::cout << "it then calculates net pay by subtracting 15%\n\n";
	std::cout << "************************************************\n\n";
}

//  *********************************************************************
//                        computePaycheck
//   
//   task:     This function takes rate and time and multiples them to
//             get gross pay and then finds net pay by subtracting 15%.
//   data in:  pay rate and time in hours worked
//   data out: the gross and net pay
//
//   ********************************************************************
void computePaycheck(float rate, int time, float gross, float net) {
	gross = rate * time;
	net   = gross - (gross * .15);
	
	std::cout << "The gross pay is $" << gross << std::endl;
	std::cout << "The net pay is   $" << net   << std::endl;
}

// The initial output is correct.
// Gross and net are pass by reference in the function to compute the paycheck.
// After changing to pass by value and including the output in the compute paycheck function.
//  the output is still correct.
