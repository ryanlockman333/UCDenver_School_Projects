/*
Ryan Lockman: 101430670
CSCI 2421:001 Fall 2013
polynomial.h
Description: Polynomial class prototypes.
*/
// Value Semantics: Copy and assignment operators mite not work for built in class.

#ifndef POlYNOMIAL_H
#define POLYNOMIAL_H

// Headers
#include <iostream>
#include <fstream>
#include <string>
#include <cassert>

class polynomial {
public:
// Default Constructor
	polynomial() : data(new int[1]), used(0) {}
	// pre: none
	// post: instantiates polynomial
		
// Destructor
	~polynomial() { free(); }
	// pre: none
	// post: destructor to deallocate memory
	
// Set Member Functions
	void setCoef(const int posIn, const int coefIn);
	// pre: posIn is > than 0 and <= used
	// post: sets the coefficient specified by posIn
	
// Get Member Functions
	int getCoef(const int posIn) const;
	// pre: posIn is > 0 and l<= used
	// post: returns the coefficient specified by posIn
	
	int getUsed() const { return used; }
	// pre: none
	// post: returns the polynomial's degree
	
// Other Member Functions
	int evaluateAt(int x);
	// pre: an x is given that is non-negative
	// post: returns Horner's Rules calculation
	
	void readFile(const std::string fileName, const int fileLine);
	// pre: a real file's name is given at correct location on drive and correct line in file
	// post: the function stores the coefficients in a int array for later use
	
	// Stream Operators
	friend std::ostream& operator<<(std::ostream &os, const polynomial &rhs);
	// pre: nothing
	// post: the function returns and ostream reference to print coefficients on screen
	
	// Arithmetic Operators
	polynomial operator+(const polynomial &rhs) const;
	// pre: a polynomial class is the left hand sign and right hand sign
	// post: returns a polynomial which equals both the polynomials added
	
	polynomial operator*(const polynomial &rhs) const;
	// pre: a polynomial class is the left hand sign and right hand sign
	// post: returns a polynomial which equals both the polynomials multiplied
	
private:
// Private Data Members
	int *data;
	int used;
	
// Private Functions
	void alloc(const int intIn);
	// pre: an int is passed in, for private use only
	// post: dynamically allocates memory for our array of ints
	
	void free();
	// pre: nothing
	// post: deallocates the memory allocated by alloc(), for private use only
	
};

#endif
