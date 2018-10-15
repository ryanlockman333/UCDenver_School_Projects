/*
This program will calculate miles into kilometres or kilometres into miles
depending on the user's choice. 
Ryan Lockman: 101430670
*/

// Headers
#include <iostream>

// Global Constants
const float KTOM = .621, MTOK = 1.61;

// Function Prototypes
float kiloToMile(float kiloIn);
float mileToKilo(float mileIn);

int main() {
	// Declarations
	float kilos = 0, miles = 0;
	int choice = 0;
	
	// Greet User
	std::cout << "This program converts miles to kilometres\n"
			  << "and also kilometres into miles.\n\n";
	
	// Loop Program
	do {
		std::cout << "\n\n        MENU      \n"
				  << "1. Miles to Kilometres\n"
				  << "2. Kilometres to Miles\n"
				  << "3. Quit\n\n"
				  << "Please enter your choice: ";
		std::cin  >> choice;
	
	// Process Choice	
	if(choice == 1) {
		std::cout << "\nPlease enter your miles to be converted: ";
		std::cin  >> miles;
		std::cout << "\n" << miles << " miles = " << mileToKilo(miles) << " kilometres";
	}
	else if(choice == 2) {
		std::cout << "\nPlease enter your kilometres to be converted: ";
		std::cin  >> kilos;
		std::cout << "\n" << kilos << " kilometres = " << kiloToMile(kilos) << " miles";
	}
		
	}while(choice != 3);
	std::cout << "\n\nGood-Bye\n\n";

	return 0;
}

// Pre_Condition:  kiloIn is of type float
// Post-Condition: The return is the kilometres converted to miles
float kiloToMile(float kiloIn) {
	return(kiloIn * KTOM);
}

// Pre_Condition:  mileIn is of type float
// Post-Condition: The return is the miles converted to kilometres
float mileToKilo(float mileIn) {
	return(mileIn * MTOK);
}