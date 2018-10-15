//  This program demonstrates the use of characters and strings
//  Ryan Lockman: 101430670

// Headers
#include <iostream>
#include <string>

// Consts
const std::string FAVORITESODA = "Dr. Dolittle";     //  use double quotes for strings
const char BESTRATING = 'A';				//  use single quotes for characters


int main() {
	char rating;						    	// 2nd highest product rating 
	std::string favoriteSnack;					    // most preferred snack
	int  numberOfPeople = 0;					// the number of people in the survey
    int  topChoiceTotal = 0;					// the number of people who prefer the top choice
	
	favoriteSnack  = "crackers";
	rating         = 'B';
	numberOfPeople = 250;
	topChoiceTotal = 148;

	std::cout << "The preferred soda is "   << FAVORITESODA        << std::endl;
	std::cout << "The preferred snack is "  << favoriteSnack       << std::endl;
	std::cout << "Out of " 				    << numberOfPeople      << " people, "
											<< topChoiceTotal 	   << " chose these items!\n";
	std::cout << "Each of these products were given a rating of "  << BESTRATING;
	std::cout << " from our expert tasters\n";
	std::cout << "The other products were rated no higher than a " << rating << std::endl;

	return 0;
}

// It is not possible to change FAVORITESODA because it is a constant, unless removed.
// It is possible to change favoriteSnack because it is not a constant.