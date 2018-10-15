/*
Ryan Lockman: 101430670
CSCI 2421:001 Fall 2013
hw2functions.cpp
Description: Global function definitions for Complex Impedance project.
*/

// Headers
#include "hw2functions.h"

// Global Functions
complex s_impedance(const double r, const double l, const double c, const double w) {
	// Pre-Condition: A user's imputed r, l, c, and w variables must be of type double.
	// Post-Condition: The new complex variable returned contains the calculated series impedance.

	complex sImp;
	
	sImp.setReal(z_R(r));
	sImp.setImag(z_L(l, w) + z_C(c, w));
	
	return sImp;
}

complex p_impedance(const double r, const double l, const double c, const double w) {
	// Pre-Condition: A user's imputed r, l, c, and w variables must be of type double.
	// Post-Condition: The new complex variable returned contains the calculated parallel impedance.

	complex pImp;
	double  zR  = 1/( 1/z_R(r) );
	double  zLC = 1/( (1/z_L(l, w)) + (1/z_C(c, w)) );
	
	pImp.setReal(zR);
	pImp.setImag(zLC);
	
	return pImp;
}

double z_R(const double r) {
	// Pre-ConditionL: A user's input r, must be of type double.
	// Post-Condition: The new double returns the calculated phasor in ohms for a circuit.
	double zR = r;
	return zR;
}

double z_L(const double l, const double w) {
	// Pre-ConditionL: A user's imputed r and w variables, must be of type double.
	// Post-Condition: The new double returns the calculated phasor in henries of a circuit.
	double zL = w*l;
	return zL;
}

double z_C(const double c, const double w) {
	// Pre-ConditionL: A user's imputed c and w variables, must be of type double.
	// Post-Condition: The new double returns the calculated phasor in farads of a circuit.
	double zC = -1/(w*c);
	return zC;
}