/*
 * field.h Field class prototypes
*/

#ifndef FIELD_H
#define FIELD_H

// Headers
#include <iostream>
#include <fstream>
#include <string>

class Field: public std::string {
public:
	// Constructors
	Field() : std::string() {}
	Field(const std::string str) : std::string(str) {} // copy 
	Field(const char *chrStr) : std::string(chrStr) {} // copy

	// Stream Operators
	friend std::istream&  operator>>(std::istream &is, Field &fld);
	friend std::ifstream& operator>>(std::ifstream &ifs, Field &fld);
};

#endif

