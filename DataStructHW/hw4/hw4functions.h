/*
Ryan Lockman: 101430670
CSCI 2421:001 Fall 2013
hw4functions.h
Description: Global function prototypes.

Pre/Post Conditions:
// Global Functions
	void readFile(const std::string fileName, Bag &bag1, Bag &bag2);
		Pre:  The correct file path is included and both data structures are of type Bag
		Post: Bag1 is filled with nouns and Bag2 is filled with verbs
	std::string grabAverb(std::string adverb[]);
		Pre:  An array of adverb strings is passed in with the correct length
		Post: Function returns a randomly generated word from the array using std::rand()
	std::string grabPrep(std::string prep[]);
		Pre:  An array of preposition strings is passed in with the correct length
		Post: Function returns a randomly generated word from the array using std::rand()
*/

#ifndef HW4FUNCTIONS_H
#define HW4FUNCTIONS_H

// Headers
#include <string>
#include "bag.h"

// Global Functions
void readFile(const std::string fileName, Bag &nounBag, Bag &verbBag);
std::string grabAdverb(std::string adverb[], int length);
std::string grabPrep(std::string prep[], int length);

#endif
