// This program will determine the batting average of a player. 
// The number of hits and at bats are set internally in the program.
// Ryan Lockman: 101430670

// Headers
#include <iostream>

// Constants
const int AT_BAT = 421;
const int HITS   = 123;

int main() {
	float batAvg = 0;

	batAvg = (float)HITS / (float)AT_BAT;						    	            //an assignment statement
	std::cout << "The batting average is " << batAvg << std::endl;   //output the result

	return 0;
}

// The batting average is 0 when ran the first time.
// No changing it to float doesn't fix the problem. The batting average is 0 when ran the second time.
