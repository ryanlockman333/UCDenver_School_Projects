/*
Ryan Lockman: 101430670
CSCI 2421:001 Fall 2013
hw2functions.h
Description: Global function prototypes for Complex Impedance project.
*/

#ifndef hw2functions_H
#define hw2functions_H

#include "complex.h"

// Global Functions
complex s_impedance(const double r, const double l, const double c, const double w);
complex p_impedance(const double r, const double l, const double c, const double w);
double  z_R(const double r);
double  z_L(const double l, const double w);
double  z_C(const double c, const double w);

#endif
