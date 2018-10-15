/*
Ryan Lockman: 101430670
CSCI 2421:001 Fall 2013
hw6functions.h
Description: Global function prototypes.
*/

#ifndef HW6FUNCTIONS_H
#define HW6FUNCTIONS_H

// Global Functions
template<typename T>
void recursiveSort(T *elems, unsigned size); // Selection Sort
// Pre:  Size >= 0
// Post: Recursively sorts an array of n elements in ascending order

template<typename T>
void fillArray(T* elems, const unsigned size, const int low, const int high);
// Pre:  Size >= 0
// Post: Returns and array filled with pseudo-random  numbers in the ranger of low to high

template<typename T>
void printArray(const T *elems, const unsigned size);
// Pre:  Size >= 0
// Post: Prints an array

void recurPatternPrint(unsigned length, int count = 0);
// Post: Recursively prints a pattern(forward and reverse triangle)

#include "hw6functions.tem"
#endif
