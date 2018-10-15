// This program prints the proverb 
// "Now is the time for all good men to come to the aid of their party"
// in a function (procedure) called Proverb that is called by the main function
// Ryan Lockman: 101430670

// Headers
#include <iostream>

// Function Prototypes
void writeProverb();  // This is the prototype for the writeProverb function 

int main() {
	writeProverb();
	return 0;
}

//  *********************************************************************
//                           writeProverb
//   
//   task:     This function prints a proverb
//   data in:  none
//   data out: none
//
//   ********************************************************************
void writeProverb() {
	std::cout << "\n\nNow is the time for all good men to come to the aid of their party.\n\n";
}
