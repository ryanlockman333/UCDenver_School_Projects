// This program will read in a group of test scores( positive integers from 1 to 100)
// from the keyboard and then calculates and outputs  the average score
// as well as the highest and lowest score. There will be a maximum of 100 scores.
// Ryan Lockman: 101430670

// Headers
#include <iostream>
#include <fstream>
using namespace std;

// Typedefs
typedef int GradeType[100];  // declares a new data type: 
                             // an integer array of 100 elements
// Function Prototypes
float findAverage (const GradeType, int);  // finds average of all grades
int   findHighest (const GradeType, int);  // finds highest of all grades
int   findLowest  (const GradeType, int);  // finds lowest of all grades
void  readFile(string fileName, GradeType &array, int &size); // reads grades in from a file into an array

int main() {
    GradeType grades;					       // the array holding the grades.
    int numberOfGrades = 0;				       // the number of grades read.
	float avgOfGrades = 0;					   // contains the average of the grades.
	int highestGrade = 0;					   // contains the highest grade.
	int lowestGrade = 0;					   // contains the lowest grade.

	readFile("gradefile.txt", grades, numberOfGrades);
	
	avgOfGrades = findAverage(grades, numberOfGrades);
	cout << endl << "The average of all the grades is " << avgOfGrades << endl;

	highestGrade = findHighest(grades, numberOfGrades);
	cout << endl << "The highest grade is " << highestGrade << endl;

	lowestGrade = findLowest(grades, numberOfGrades);
	cout << endl << "The lowest grade is " << lowestGrade << endl;
	
	return 0;
}

//****************************************************************************
//                                 findAverage
//
// task:          This function receives an array of integers and its size.
//                It finds and returns the average of the numbers in the array
// data in:       array of floating point numbers
// data returned: avarage of the numbers in the array
//
//****************************************************************************
float findAverage (const GradeType  array, int size) {  
	float sum = 0;   // holds the sum of all the numbers
	
    for(int pos = 0; pos < size; pos++)	
	   sum = sum + array[pos];

    return (sum / size);  // returns the average   
}

//****************************************************************************
//                                 findHighest
//
// task:          This function receives an array of integers and its size.
//                It finds and returns the highest value of the numbers in
//                the array
// data in:       array of floating point numbers
// data returned: highest value of the numbers in the array
//
//****************************************************************************
int   findHighest (const GradeType array, int size) {
	float highest = 0;

	for(int pos = 0; pos < size; ++pos)
		if(array[pos] > highest)
			highest = array[pos];
			
	return highest;
}


//****************************************************************************
//                                 findLowest
//
// task:          This function receives an array of integers and its size.
//                It finds and returns the lowest value of the numbers in 
//                the array
// data in:       array of floating point numbers
// data returned: lowest value of the numbers in the array
//
//****************************************************************************
int   findLowest  (const GradeType array, int size) {
	float lowest = array[0];

	for(int pos = 0; pos < size; ++pos)
		if(array[pos] < lowest)
			lowest = array[pos];
			
	return lowest;
}

/*
void readFile(string fileName, GradeType &array, int &size);
Pre:  correct file path is given
Post: fills array with grades read in from file and stores size
*/
void readFile(string fileName, GradeType &array, int &size) {
	float fltIn = 0;
	ifstream inFile(fileName.c_str());
	if(!inFile) {
		std::cout << "\nError opening file for reading.\n";
		return;
	}
	
	int pos = 0;
	while(inFile.good()) {
		inFile >> fltIn;
		array[pos] = fltIn;
		++pos;
	}
	inFile.close();
	
	size = pos;
}

/* Exercise 1
The average of all the grades is 67.5
The highest grade is 90
The lowest grade is 45
*/
