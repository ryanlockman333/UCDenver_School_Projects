// This program prints "You Pass" if a student's average is 
// 60 or higher and prints "You Fail" otherwise
// Ryan Lockman: 101430670

// Headers
#include <iostream>

int main() {
	float average = 0;    // holds the grade average

	std::cout << "Input your average: ";
	std::cin  >> average;

	if     (average >= 90 && average <= 100)
		std::cout << "\nYou have an A\n";
	else if(average >= 80 && average <= 89)
		std::cout << "\nYou have a B\n";
	else if(average >= 60 && average <= 79)
		std::cout << "\nYou Pass\n";
	else if(average >= 0 &&  average <= 59)
		std::cout << "\nYou Fail\n";
	else
		std::cout << "\nInvalid data\n";

    return 0;	
}

// When inputting 60 as average you fail because its not >= average.
// When inputting a negative number my program says invalid data because 
//  I put an else statement at the end for any unwanted data entries for > 100 or < 0.
