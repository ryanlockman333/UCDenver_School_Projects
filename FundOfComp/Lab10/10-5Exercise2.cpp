// Ryan Lockman: 101430670

// Headers
#include <iostream>
#include <cstring>

int main() {
	char name1[25];
	char name2[25];
	
	std::cout << "\nPlease enter first name(example Lockman, Ryan):\n";
	std::cin.getline(name1, 25);
	
	std::cout << "\nPlease enter second name(example Lockman, Ryan):\n";
	std::cin.getline(name2, 25);

	if(strcmp(name1, name2) > 0)
		std::cout << "\n\nThe names are as follows:"
				  << std::endl << name2
		          << std::endl << name1;
	else if(strcmp(name1, name2) < 0)
		std::cout << "\n\nThe names are as follows:"
				  << std::endl << name1
				  << std::endl << name2;
	else if(strcmp(name1, name2) == 0)
		std::cout << "\n\nThe names are as follows:"
				  << std::endl << name1
            	  << std::endl << name2
		          << "\nThe names are the same";
		
	return 0;
}
