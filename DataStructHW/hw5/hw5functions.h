/*
Ryan Lockman: 101430670
CSCI 2421:001 Fall 2013
hw5functions.h
Description: Global function prototypes.

Pre/Post Conditions:
// Global Functions
	void readFile(const std::string fileName, set_type &s1, set_type &s2, set_type &s3);
		Pre:  The correct file path is included
		Post: All 3 Sets are filled with the specified data
*/

#ifndef HW5FUNCTIONS_H
#define HW5FUNCTIONS_H

// Headers
#include <string>
#include "set.h"

// Global Functions
template<typename set_type>
void readFile(const std::string fileName, set_type &s1, set_type &s2, set_type &s3);

#include "hw5functions.tem"
#endif
