// This program will input the value of two sides of a right triangle and then 
// determine the size of the hypotenuse.
// Ryan Lockman: 101430670

// Headers
#include <iostream>
#include <iomanip>
#include <cmath>         // needed for math functions like sqrt()

int main() {

	float a   = 0, b = 0;  // the smaller two sides of the triangle
	float hyp = 0;		   // the hypotenuse calculated by the program
   
	std::cout << "Please input the value of the two sides(separated by a space): " << std::endl;
	std::cin  >> a >> b;

	hyp = sqrt( pow(a, 2) + pow(b, 2) );
	
	std::cout << "The sides of the right triangle are " << a << " and " << b << std::endl;
	std::cout << std::setprecision(2) << std::fixed << std::showpoint;
	std::cout << "The hypotenuse is " << hyp << std::endl;

	return 0;
}

// The hyp formula can be implemented through cmath, with the use of the sqrt() and pow() functions.
