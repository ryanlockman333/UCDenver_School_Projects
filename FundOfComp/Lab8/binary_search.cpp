// This program demonstrates a Binary Search
// Ryan Lockman: 101430670

// Headers
#include<iostream>
using namespace std;

// Global Constants
const int SIZE = 16;

// Function Prototypes
int binarySearch(int [], int, int);

int main() {
	int found, value;
	int array[] = {0,2,2,3,5,9,11,12,12,12,13,17,18,19,19,34}; // array to be searched
	
	cout << "\nEnter an integer to search for: ";
	cin  >> value;

	found = binarySearch(array, SIZE, value); //function call to perform the binary search
	                                          //on array looking for an occurrence of value
	if(found == -1)
		cout << "The value " << value << " is not in the list" << endl;
	else
		cout << "The value " << value << " is in position number "
		     << found + 1 << " of the list" << endl;
			 
	return 0;
}


//*******************************************************************
//                     binarySearch
//
// task:		  This searches an array for a particular value
// data in:       List of values in an ordered array, the number of 
//                elements in the array, and the value searched for
//                in the array
// data returned: Position in the array of the value or -1 if value
//                not found
//
//*******************************************************************
int binarySearch(int array[], int numElems, int value) {
	int first = 0;				    // First element of list
	int last = numElems - 1;	    // last element of the list
	int middle;					    // variable containing the current 
	                                // middle value of the list
	
	while(first <= last) {
		middle = first + (last - first) / 2; 

		if(array[middle] == value)
			return middle;		       // if value is in the middle, we are done
	    else if(array[middle] > value)
			last = middle - 1;		   // toss out the second remaining half of
		else						   // the array and search the first 
			first = middle + 1;		   // toss out the first remaining half of
									   // the array and search the second
	}
	return -1;					       // indicates that value is not in the array
}

// Yes it is.
// Middle is defined by how much of the array is left to search. By taking the
//  first position and last position of the remaining portion and determining its middle.
// It effects the logic of the program by dividing its searching time in half every time.

// Enter an integer to search for: 19
// The value 19 is in position number 2 of the list
// Enter an integer to search for: 12
// The value 12 is in position number 8 of the list

// The value of 19 was found at its first occurrence.
// The vlaue of 12 was found at its second occurrence.
// The reason that it found the second occurrence of 12 an not first or third is because
//  12 is the middle of the list, so when it starts the binary search it checks if its the middle
//   and it is.
// For 19 after going through the binary search and dividing the list in half three times, the first
//  occurrence of 19 becomes the middle of third divide.
