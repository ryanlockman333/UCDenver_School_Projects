/*
Ryan Lockman: 101430670
CSCI 2421:001 Fall 2013
complex.cpp
Description: Complex class definitions.
*/

// Headers
#include <iostream>
#include <cmath>
#include "complex.h"

// Other Member Functions
double complex::mag() const {
	// Pre-Condition: none
	// Post-Condition: Returns a variable, magResult, with the calculated complex magnitude.
	double magResult = sqrt(pow(real, 2) + pow(imag, 2));
	return magResult;
}

double complex::arg() const {
	// Pre-Condition: none
	// Post-Condition: Returns a variable, argResult, with the calculated polar form.
	double argResult = atan2(imag, real) * (180/PI);
	return argResult;
}

void complex::displayFunc() {
	// Pre-Condition: none
	// Post-Condition: The complex variable is printed to the screen in the format of (x, y).
	std::cout << "(" << real << ", " << imag << ")";
}

// Arithmetic Operators
complex complex::operator+(const complex &rhs) const {
	// Pre-Condition: A complex class must be the left and right hand sign.
	// Post-Condition: The new complex variable contains the addition of both the lhs and rhs.
	return complex(this->getReal() + rhs.getReal(), this->getImag() + rhs.getImag());
}

complex complex::operator-(const complex &rhs) const {
	// Pre-Condition: A complex class must be the left and right hand sign.
	// Post-Condition: The new complex variable contains the subtraction of the rhs from the lhs.
	return complex(this->getReal() - rhs.getReal(), this->getImag() - rhs.getImag());
}

complex complex::operator*(const complex &rhs) const {
	// Pre-Condition: A complex class must be the left and right hand sign.
	// Post-Condition: The new complex variable contains the multiplication of both the lhs and rhs.
	return complex(this->mag() * rhs.mag(), this->arg() + rhs.arg());
}

complex complex::operator/(const complex &rhs) const {
	// Pre-Condition: A complex class must be the left and right hand sign.
	// Post-Condition: The new complex variable contains the division of the rhs from the lhs.
	return complex(this->mag() / rhs.mag(), this->arg() - rhs.arg());
}
