// This program has the user input a number n and then finds the
// mean of the first n positive integers
// Ryan Lockman: 101430670

// Headers
#include <iostream>
using namespace std;


int main() {
	int value1 = 0, value2 = 0;       // value is some positive number n
 	int total  = 0;       			   // total holds the sum of the first n positive numbers
   	int number = 0;                   // the amount of numbers
  	float mean = 0;                   // the average of the first n positive numbers

  	cout << "Please enter two positive integers, one marking "
			"\nthe beginning and the other marking the end"
			"\n(separated by a space)" << endl;
   	cin  >> value1 >> value2;

  	if(value1+value2 > 0) {
      	for(number = 1; number <= value1+value2; number++)
 	  	    total = total + number; 
		
        mean = total / (value1+value2);         // note the use of the typecast 
		                                                            // operator here
		cout << "The mean average of the first positive integer " << value1
             << " and second positive integer " << value2 << " is "
			 << mean << endl;
    }
    else 
        cout << "Invalid input - integer must be positive" << endl;

   return 0;	
}

// The type cast operator is needed because total and value are ints.
// If you remove the type cast then the value is rounded down to 1 for an even 2 an odd 3 stays at a 2.
// When you enter in 2.99 it says 1,5, the same as entering in a 2.
