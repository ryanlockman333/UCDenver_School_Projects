// This program uses a selection sort to arrange an array of integers in 
// descending order
// Ryan Lockman: 101430670

// Headers
#include<iostream>
using namespace std;

// Function Prototypes
void selectionSortArray(int [], int);   
void displayArray(int[], int);

// Global Constants
const int SIZE = 5;

int main() {
	int values[SIZE] = {9,2,0,11,5};
	
	cout << "\nThe values before the selection sort is performed are:" << endl;
	displayArray(values, SIZE);
	
	cout << "\n\nThe values during the selection sort's performance are:" << endl;
	selectionSortArray(values, SIZE);
	
	cout << "\n\nThe values after the selection sort is performed are:" << endl;
	displayArray(values, SIZE);
	
	return 0;
}

//******************************************************************
//                      displayArray
//
// task:	  	  to print the array
// data in:       the array to be printed, the array size
// data out:      none
//
//******************************************************************
void displayArray(int array[], int elems) {
	for(int count = 0; count < elems; count++)
		cout << array[count] << "  ";
    cout << endl;
}

//******************************************************************
//                      selectionSortArray
//
// task:		  to sort values of an array in ascending order
// data in:       the array, the array size
// data out:      the sorted array
//
//******************************************************************
void selectionSortArray(int array[], int elems) {
	int seek;      //array position currently being put in order
	int minCount;  //location of smallest value found
	int minValue;  //holds the smallest value found
	
	for(seek = 0; seek < (elems-1); seek++) {   // outer loop performs the swap
		minCount = seek;                        // and then increments seek
		minValue = array[seek];
		for(int index = seek + 1; index < elems; index++) {
	      	  // inner loop searches through array     
			  // starting at array[seek] searching
			  // for the smallest value. When the 
			  // value is found, the subscript is
			  // stored in minCount. The value is    
			  // stored in minValue.
		
			if(array[index] > minValue) {
				minValue = array[index];                                                     
				minCount = index;       
			}
		}

			// the following two statements exchange the value of the
			// element currently needing the smallest value found in the 
		    // pass(indicated by seek) with the smallest value found
		    // (located in minValue)

		array[minCount] = array[seek];  
		array[seek] = minValue;
		displayArray(array, SIZE);
	}
}

// After doing the selection sort by hand on a sheet of paper, the output is the same as
//  each step that was printed on the program screen.
