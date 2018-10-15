/*
Ryan Lockman: 101430670
Project: Palindrome
Description: Prompts the user to enter up to 50 characters
			 and then tells the user if the word is a 
			 palindrome or not.
*/

// Headers
#include <iostream>
#include <string>

int main() {
	char cword[50];
	
	std::cout << "\nEnter a word that is 50 characters or less:\n";
	std::cin.getline(cword, 50);
	
	std::string word = cword;
	
	if(word == std::string(word.rbegin(), word.rend()))
		std::cout << "\nThe word is a palindrome.\n";
	else
		std::cout << "\nThe word is not a palindrome.\n";
	
	return 0;
}
