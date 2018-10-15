/*
Ryan Lockman: 101430670
CSCI 2421:001 Fall 2013
hw4.cpp - Driver File
Project: Random Sentences
Description: This program randomly generates 5 sentences through the use of Bag data
			 structures(read in through a file) and string arrays.
*/

// Headers
#include <iostream>
#include <cstdlib>
#include "bag.h"
#include "hw4functions.h"

int main(int argc, char *argv[]) {
	// Declarations
	std::string prep[5]   = {"I", "We", "She", "They", "He"};
	std::string adverb[5] = {"cautiously", "quickly", "constantly", "continuously", "slowly"};
	Bag nounBag;
	Bag verbBag;
	
	// Read File
	if(argc != 2)
		readFile("data.txt", nounBag, verbBag);
	else {
		std::cout << "\nThe number of arguments: " << argc
				  << "\nThe name of the file:    " << argv[0];
		readFile(argv[1], nounBag, verbBag);
	}
	
	// Output
	std::cout << "\n\nThis program randomly generates 5 sentences.\n\n";
	srand((unsigned)time(NULL));
	for(int i = 0; i != 5; ++i)
		std::cout << grabPrep(prep, 5) << " " << grabAdverb(adverb, 5) << " "
				  << verbBag.grab()    << " " << nounBag.grab()        << ".\n";
	
	return 0;
}
