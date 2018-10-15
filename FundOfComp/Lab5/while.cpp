// Ryan Lockman: 101430670

// Headers
#include <iostream>

int main() {
	char letter = 'a';

    do {
		std::cout << "Please enter a letter('x' to quit):" << std::endl;
        std::cin >> letter;
        std::cout << "The letter you entered is: " << letter << std::endl;
    }while(letter != 'x');

    return 0;	
}

// Its not user friendly because you don't know what to enter to get out of your loop.
// The program would still execute correctly. But the do while loop executes its body at least once,
//  unlike the while loop.