/*
Ryan Lockman: 101430670
CSCI 2421:001 Fall 2013
array.cpp
Description: Array template class prototypes.
*/

#ifndef ARRAY_H
#define ARRAY_H

// Headers
#include <iostream>
#include <algorithm>

template<class T> class Array {
public:
	// Typedefs
	typedef T value_type;
	typedef unsigned size_type;
	
	// Member Constants
	static const size_type DEFAULT_SIZE = 15;

	// Constructors
	Array(size_type initial_capacity = DEFAULT_SIZE) // Default
		: data(new value_type[initial_capacity]), used(0), capacity(initial_capacity) {}
		
	// Copy Constructor
	Array(const Array &rhs);
	
	// Destructor
	~Array() { free(); }
	
	// Assignment Operator
	Array<T>& operator=(const Array &rhs);

	// Constant Member Functions
	size_type size() const {return used;}
	
	// Modification Member Functions
	
	
	// Operator Overload Functions
	value_type& operator[](int idx);
	const value_type& operator[](int idx) const;
	Array<T>& operator+=(const Array &rhs);
	
private:
	// Data Members
	value_type *data;
	size_type  used, capacity;
	
	// Private Member Functions
	void free();
};

// Non-Member Functions
template<class T>
inline Array<T> operator+(Array<T> lhs, const Aray<T>& rhs) {
  lhs += rhs;
  return lhs;
}

#include "array.tem"
#endif
