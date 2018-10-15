// This program illustrates the use of logical operators
// Ryan Lockman: 101430670

// Headers
#include <iostream>

int main() {
 	char year;
    float gpa = 0;

    std::cout << "What year student are you ?";
    std::cout << "\nEnter 1 (freshman), 2 (sophomore), 3 (junior), or 4 (senior): ";
	std::cin  >> year;

    std::cout << "Now enter your GPA: ";
    std::cin  >> gpa;

	if(gpa >= 2.0 && year == '4')
		std::cout << "It is time to graduate soon\n";      
    else if(year != '4' || gpa < 2.0)
        std::cout << "You need more schooling\n";

    return 0;	
}

// You cant replace the >= 2.0 with a NOT because if it was a 3.0 or 4.0,
//  it would say you need more schooling. You could replace == '4' with != '4' though.
// You can replace year != 4 with < 4 or <= 3.
// For exercise 3 when you do the replacing then any student with a 2.0 or above
//  will graduate even if they are  not on there 4th year. Also if you are not on your 4th year
//  and have a gpa less than 2, then you need more schooling. Doesn't handle the right.
// You can replace it with a single word else, but you would have to get rid of the 
//  (year != '4' || gpa < 2.0) with just the else.
