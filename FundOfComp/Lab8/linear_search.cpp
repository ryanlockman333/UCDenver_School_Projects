// This program performs a linear search on a integer array
// Ryan Lockman: 101430670

// Headers
#include<iostream>
using namespace std;

// Global Constants
const int SIZE = 8;

// Function Prototypes
int searchList(int[], int, int);

int main() {
	int array[SIZE] = {3, 6, -19, 5, 5, 0, -2, 99};
	int found;
	int intIn;

	cout << "\nEnter a number to search for(-999 to end program): ";
	cin  >> intIn;
	
	while(intIn != -999) {
		found = searchList(array, SIZE, intIn);

		if(found == -1)
			cout << "The letter " << intIn 
				 << " was not found in the list" << endl;
		else
			cout << "The letter " << intIn <<" is in the " << found + 1
				 << " position of the list" << endl;
				 
		cout << "\nEnter a number to search for(-999 to end program): ";
		cin  >> intIn;
	}
	
	return 0;

}

//*******************************************************************
//                      searchList
//
// task:	      This searches an array for a particular value
// data in:       List of values in an array, the number of 
//                elements in the array, and the value searched for
//                in the array
// data returned: Position in the array of the value or -1 if value
//                not found
//
//*******************************************************************
int searchList(int List[], int numElems, int value) {
	for(int count = 0; count < numElems; count++) {
		if(List[count] == value)
                      // each array entry is checked to see if it contains
	                  // the desired value.
		 return count; 
                     // if the desired value is found, the array subscript
			         // count is returned to indicate the location in the array
	}
	return -1;	     // if the value is not found, -1 is returned
}

// When you search for the number 5, it returns the first occurrence of that value
//  which would be at position 4, or [3] in the actual array.

// A pre-test loop would be ideal because when you enter in -999 to end the program
//  it wont check if that value is in the array of integers.
