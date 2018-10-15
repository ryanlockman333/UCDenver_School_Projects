/*
 This program prompts the user  for the number of tellers
 at Nation’s Bank  in Hyatesville that worked each  of the last three 
 years. Each  worker is asked for the number of days
 out sick for each  of the last three  years. The displays the
 number of tellers  and the total number of days  missed  by all the tellers
 over the last three  years.
 Ryan Lockman: 101430670
 */
 
 // Headers
 #include <iostream>
 
 int main() {
	// Declarations
	int tellers = 0, daysSick = 0, daysTotal = 0;
 
	// Input
	std::cout << "How many tellers worked at Nation’s Bank for\n"
                 "each of the last three years: ";
	std::cin  >> tellers;
	
	// Input Loop
	for(int i = 1; i <= tellers; i++)
		for(int j = 1; j <= 3; j++) {
			std::cout << "\nHow many days was teller " << i
			          << "\nout sick during year " << j << ": ";
			std::cin  >> daysSick;
			daysTotal = daysTotal+daysSick;
		}
 
	// Output
	std::cout << "\n\nThe " << tellers << " teller(s) were out sick for"
			  << "\na total of " << daysTotal << " days during the last 3 years.";
 
	return 0;
}
