// This program illustrates the use of a sentinel in a while loop.
// The user is asked for monthly rainfall totals until a sentinel
// value of -1 is entered. Then the total rainfall is displayed
// Ryan Lockman: 101430670

// Headers
#include <iostream>

int main() {
	// Fill in the code to define and initialize to 1 the variable month 
	float total = 0, rain = 0;
	int   month = 1;

	std::cout << "Enter the total rainfall for month " << month << std::endl;
	std::cout << "Enter -1 when you are finished" << std::endl;
	// Fill in the code to read in the value for rain
	std::cin  >> rain;
	
	// Fill in the code to start a while loop that iterates 
	// while rain does not equal -1
	while(rain != -1) {
		// Fill in the code to update total by adding it to rain
		total = total + rain;
		// Fill in the code to increment month by one
		month++;
	    std::cout << "Enter the total rainfall in inches for month "
	         << month << std::endl;
		std::cout << "Enter -1 when you are finished" << std::endl;
		// Fill in the code to read in the value for rain
		std::cin >> rain;
	}

	if (month == 1)
		std::cout << "No data has been entered" << std::endl;
	else
		std::cout << "The total rainfall for the " << month-1 
		     << " months is "<< total << " inches." << std::endl;

   return 0;	
}

// When I enter in 1 for each month total rain = 12, when I enter
//  in 10 for each month I get 120 total rainfall. Output is correct.
// When I enter in -1 first, No Data has been entered appears.
// When I enter 0 for all months it stays 0, 0 works.
// When I enter in another number besides -1, like -5, you get an undetected error,
//  because you can't have negative rain amount.
// The reason behind the month == 1, No Data. Is that you entered in -1 to start,
//  so no data was entered in and month is still = 1. You "basically" quit early.
