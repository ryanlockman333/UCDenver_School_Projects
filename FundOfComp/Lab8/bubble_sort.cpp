// This program uses a bubble sort to arrange an array of integers in 
// descending order
// Ryan Lockman: 101430670

// Headers
#include<iostream>
using namespace std;

// Function Prototypes
void bubbleSortArray(int [], int);
void displayArray(int[], int);

// Global Constants
const int SIZE = 9;

int main() {
	int values[SIZE] = {23,0,45,-3,5,-78,1,-1,9};

	cout << "\nThe values before the bubble sort is performed are:" << endl;
	displayArray(values, SIZE);

	cout << "\n\nThe values during the bubble sort's performance are:" << endl;
	bubbleSortArray(values, SIZE);

	cout << "\n\nThe values after the bubble sort is performed are:" << endl;
	displayArray(values, SIZE);

	return 0;
}

//******************************************************************
//                      displayArray
//
// task:		to print the array
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
//                      bubbleSortArray
//
// task:		to sort values of an array in ascending order
// data in:       the array, the array size
// data out:      the sorted array
//
//******************************************************************
void bubbleSortArray(int array[], int elems) {
	bool swap;
	int  temp = 0;
	int  bottom = elems - 1;     // bottom indicates the end part of the 
	                            // array where the largest values have
	                            // settled in order
	do {
		swap = false;
		for(int count = 0; count < bottom; count++) {
			if(array[count] < array[count+1]) {
				            // the next three lines do a swap   
			   temp = array[count];  
			   array[count] = array[count+1];
			   array[count+1] = temp;
			   swap = true; // indicates that a swap occurred
			}
			displayArray(array, SIZE);
		}
            bottom--;       // bottom is decremented by 1 since each pass through
	                        // the array adds one more value that is set in order
	            
	}while(swap != false);
                            // loop repeats until a pass through the array with
	                        // no swaps occurs
}

// After doing the bubble sort by hand on a sheet of paper, the output is the same as
//  each step that was printed on the program screen.
