// This program calculates the area and perimeter of a rectangle.
// Ryan Lockman: 101430670

// Headers
#include <iostream>

// Consts
const double LENGTH = 8;
const double WIDTH  = 3;

int main() {
	float area		= 0;
	float perimeter = 0;

	area      = LENGTH * WIDTH;
	perimeter = 2 * LENGTH + 2 * WIDTH;

	std::cout << "The area of the rectangle is: "       << area      << std::endl;
	std::cout  << "The perimeter of the rectangle is: " << perimeter << std::endl;

	return 0;
}
