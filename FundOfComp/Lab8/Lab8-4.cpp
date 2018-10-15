/*
Program: Lab 8.4
Ryan Lockman: 101430670
*/

// Headers
#include <iostream>

// Global Constants
const unsigned MAX = 50;

// Function Prototypes
void  fillArray(int[], const unsigned);
void  printArray(int[], const unsigned);
void  bubbleSort(int[], const unsigned);
int   binarySearch(int[], const unsigned, const int);
float mean(int[], const unsigned);

int main() {
	// Declarations
	int 	 iA[MAX],  value  = 0;
	unsigned size = 0, found  = 0;
	float    avg  = 0;

	std::cout << "\nHow many values would you like to store in your array: ";
	std::cin  >> size;
	fillArray(iA, size);
	
	std::cout << "\nWhat value would you like to search for: ";
	std::cin  >> value;
	
	std::cout << "\n\nThe size of the array: " << size;
	std::cout << "\nThe array before being sorted: ";
	printArray(iA, size);
	
	std::cout << "\nThe array after being sorted: ";
	bubbleSort(iA, size);
	printArray(iA, size);
	
	std::cout << "\nThe value being searched is: " << value;
	
	found = binarySearch(iA, size, value);
	if(found == -1)
		std::cout << "\nThe value " << value << " was not in the array.";
	else
		std::cout << "\nThe value " << value << " was at position number "
		          << found+1 << " of the array.";
	
	avg = mean(iA, size);
	std::cout << "\nThe mean of the array: " << avg;
	
	return 0;
}

// Function Definitions
void fillArray(int aIn[], const unsigned size) {
	for(int i = 0; i < size; ++i) {
		std::cout << "\nEnter in a value for position " << i+1 << ": ";
		std::cin  >> aIn[i];
	}
}

void printArray(int aIn[], const unsigned size) {
	for(int i = 0; i < size; ++i)
		std::cout << aIn[i] << " ";
}

void bubbleSort(int aIn[], const unsigned size) {
	bool swap;
	int  tmp    = 0;
	int  bottom = size-1;
	do {
		swap = false;
		for(int i = 0; i < bottom; ++i)
			if(aIn[i] > aIn[i+1]) {
			   tmp      = aIn[i];  
			   aIn[i]   = aIn[i+1];
			   aIn[i+1] = tmp;
			   swap = true;
			}
            --bottom;          
	}while(swap != false);
}

int binarySearch(int aIn[], const unsigned size, const int value) {
	unsigned first  = 0;
	unsigned last   = size-1;
	unsigned middle = 0;
	
	while(first <= last) {
		middle = first + (last-first) / 2; 

		if(aIn[middle] == value)
			return middle;
	    else if(aIn[middle] > value)
			last = middle - 1;
		else
			first = middle + 1;
	}
	return -1;				
}

float mean(int aIn[], const unsigned size) {
	float sum = 0;
	
	for(int i = 0; i < size; ++i)
		sum += aIn[i];
	
	sum /= size;
	
	return sum;
}
