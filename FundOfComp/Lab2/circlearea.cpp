// This program will output the circumference and area
// of the circle with a given radius.
// Ryan Lockman: 101430670

// Headers
#include <iostream>

// Consts
const double PI     = 3.14;
const double RADIUS = 5.4;

int main() {
	float area 			= 0;			  	  // definition of area of circle
	int   circumference = 0;				  // definition of circumference
	
    circumference = 2 * PI * RADIUS;		  // computes circumference
    area 		  = PI * RADIUS * RADIUS;     // computes area
	
	std::cout << "The circumference of the circle is: " << circumference << std::endl;
	std::cout << "The area of the circle is: " 			<< area 		 << std::endl;
	
	return 0;
}

// The circumference of the circle is 33 
// The area of the circle is 91.5624
// When changed from float to int, the circumference is an integer of 33 instead of a decimal of 33.912