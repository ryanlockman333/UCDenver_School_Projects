/*
Ryan Lockman: 101430670
Project: readdata.cpp
Description:
*/

// Headers
#include <iostream>

int main() {
	char last[10] = {'\0'};

	std::cout << "\nPlease enter your last name with no more"
			  << "\nthan 9 characters: ";
	std::cin.getline(last, 10);
	std::cout << "\nOUTPUT\n"
			  << "\n" << last << "\n";

	return 0;
}

// When I enter in newmanouskous it prints out the whole name. This would be a buffer overflow
//  because the char array can only hole a maximum of 9. I get a segmentation fault(core dump),
//  if I enter in about 20 characters.
// When using cin.getline() and entering in newmanouskous, your out put is only newmanous.
//  It only outputs the first 9 characters, no overflow.
