/*
Ryan Lockman: 101430670
CSCI 2421:001 Fall 2013
complex.h
Description: Complex class prototypes.
*/

#ifndef COMPLEX_H
#define COMPLEX_H

// Constant Members
const double PI = 3.14159265;

class complex {
public:
	// Constructors
	complex() : real(0), imag(0) {}
	complex(double rIn, double iIn) : real(rIn), imag(iIn) {}
	
	// Set Member Functions
	void setReal(double rIn) {real = rIn;}
	void setImag(double iIn) {imag = iIn;}
	
	// Const Member Functions
	double getReal() const {return real;}
	double getImag() const {return imag;}
	
	// Other Member Functions
	double mag() const;
	double arg() const;
	void   displayFunc();
	
	// Arithmetic Operators
	complex operator+(const complex &rhs) const;
	complex operator-(const complex &rhs) const;
	complex operator*(const complex &rhs) const;
	complex operator/(const complex &rhs) const;
	
private:
	// Data Members
	double real, imag;
};

#endif
