// This program illustrates the use of the Switch statement.
// Ryan Lockman: 101430670

// Headers
#include <iostream>

int main() {
	char grade;

	std::cout << "What grade did you earn in Programming I: ";
	std::cin >> grade;

	if	   (grade == 'A')
			std::cout << "YOU PASSED!\n an A - excellent work !\n";
	else if(grade == 'B')
			std::cout << "YOU PASSED!\n you got a B - good job\n";
	else if(grade == 'C')
			std::cout << "YOU PASSED!\n earning a C is satisfactory\n";
	else if(grade == 'D')
			std::cout << "YOU PASSED!\n while  D is passing, there is a problem\n";
    else if(grade == 'F')
			std::cout << "you failed - better luck next time\n";
    else
			std::cout << "You did not enter an A, B, C, D, or F\n";

    return 0;	
}

// When removing the breaks it prints out every case, not just one.
// Yes I used a trailing else. It served as the default: in the switch statement.
