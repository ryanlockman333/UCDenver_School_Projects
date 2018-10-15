// This program will allow the user to input from the keyboard
// a word to the following proverb:
// "Now is the time for all good men to come to the aid of their _______"
// Ryan Lockman: 101430670

// Headers
#include <iostream>
#include <string>

// Function Prototypes
void writeProverb(std::string wordIn);

int main () {
	std::string word;

	std::cout << "Given the phrase:" << std::endl;
	std::cout << "Now is the time for all good men to come to the aid of their ______" << std::endl;
	std::cout << "Input a word to be added at the end of the phrase." << std::endl;
	std::cout << "Please input your word now" << std::endl;
	std::cin  >> word;
	std::cout << std::endl;
    writeProverb(word);

	return 0;
}

//  ******************************************************************************
//                            writeProverb
//   
//   task:      This function prints a proverb. The function takes a string
//              from the call. Then prints "Now is the time for all good men
//              to come to the aid of their _______". Appending the string to
//				the end of the sentence.
//   data in:   code for ending word of proverb (string)
//   data out:  none
//
//   *****************************************************************************


void writeProverb(std::string wordIn) {
	std::cout << "\n\nNow is the time for all good men to come to the aid of their " << wordIn << ".\n\n";
}

// When you enter in a float or a negative float number, it still prints the second option "country",
//  because any other option besides 1 prints the second option.
// Here is the code from exercise 2.
/*void writeProverb(int wordCodeIn) {
	if(wordCodeIn == 1)
		std::cout << "\n\nNow is the time for all good men to come to the aid of their party.\n\n";
    else if(wordCodeIn == 2)
		std::cout << "\n\nNow is the time for all good men to come to the aid of their country.\n\n";
	else
		std::cout << "\n\nInvalid Argument, Please enter 1 or 2.\n\n";
}*/