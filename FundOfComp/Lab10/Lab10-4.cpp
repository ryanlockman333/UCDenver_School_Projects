// Ryan Lockman: 101430670

// Headers
#include <iostream>
#include <cstring>

int main() {
	char string1[20] ="Total Eclipse ";
	char string2[11] = "of the Sun";
	
	std::cout << string1 << std::endl;
	std::cout << string2 << std::endl;
	
	strcat(string1, string2);
	
	std::cout << string1 << std::endl;

	return 0;
}

// Exercise 1 - results when ran were
/*
Total Eclipse
of the Sun
Total Eclipse of the Sun
*/
// Exercise 2 - results when ran were
/*
Total Eclipse
of the Sun
Total Eclipse of the Sun
*/
// Results look the same because string1 is only 14 characters long
//  and there would still be 5 spaces left in the cstring for more characters,
//  doesn't cut any off.
