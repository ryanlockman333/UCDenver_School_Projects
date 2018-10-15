/*
Ryan Lockman: 101430670
CSCI 2421:001 Fall 2013
hw2.cpp
Project: Phasor Impedance
Description: This program calculates a series and parallel RLC circuit's phasor impedance
			 with the help of a complex number class.
*/

// Headers
#include <iostream>
#include "complex.h"
#include "hw2functions.h"

// write pre/post conditions


int main() {
	// Declarations
	double r = 0, l = 0, c = 0, w = 0;	
	
	// Input
	std::cout << "Hello!\nHere we have a program to help a user compute a series and parallel\n"
				 "RLC circuit's phasor impedance(Z).\n\n";		 
	std::cout << "\nPlease enter the resistor(R) value in ohms:    ";
	std::cin  >> r;
	std::cout << "\nPlease enter the inductor(L) value in henries: ";
	std::cin  >> l;
	std::cout << "\nPlease enter the capacitor(C) value in farads: ";
	std::cin  >> c;
	std::cout << "\nPlease enter the sinusoidal steady state frequency(w) in rad/sec: ";
	std::cin  >> w;
	
	// Computations
	complex zR(z_R(r), 0);
	complex zL(0, z_L(l, w));
	complex zC(0, z_C(c, w));
	
	complex sI = s_impedance(r, l, c, w);
	complex pI = p_impedance(r, l, c, w);
	
	// Output
	std::cout << "\n\nInput:   R = " << r << " ohms, L = " << l << " henries, C = " << c
			  << " farads, Frequency = " << w << " radians/sec\n";
	std::cout << "\nPhasors: Zr = ";				  zR.displayFunc();
	std::cout << ", Zl = ";		     				  zL.displayFunc();
	std::cout << ", Zc = ";		     				  zC.displayFunc();
	std::cout << "\n\nComplex series impedance   = "; sI.displayFunc();
	std::cout << "\nComplex parallel impedance = ";   pI.displayFunc();
	
	return 0;
}
