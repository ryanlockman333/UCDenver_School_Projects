// This program tests whether or not an initialized value
// is equal to a value input by the user 
// Ryan Lockman: 101430670

// Headers
#include <iostream>

int main( ) {
 	int num1 = 0, num2 = 0;           

    std::cout << "Please enter an integer: ";
	std::cin  >> num1;
	std::cout << "Please enter another integer: ";
	std::cin  >> num2;
	std::cout << "\nnum1 = " << num1 << " and num2 = " << num2;

    if(num1 == num2)
		std::cout << "\nThe values are the same. \nHey, that's a coincidence!\n"; 
	else
		std::cout << "\nThe values are not the same\n";
			
    return 0;	
}

// When ran the program is not doing what you would expect because num1 = num2 needs to be num1 == num2.
// After fixing the error, everything runs correct.
// When switching to an if/else, the same results are seen.
