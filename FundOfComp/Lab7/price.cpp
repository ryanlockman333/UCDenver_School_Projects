// This program will read in prices and store them into a two-dimensional array
// It will print those prices in a table form.
// Ryan Lockman: 101430670

#include <iostream>
#include <iomanip>
using namespace std;


// Global Constants
const int MAXROWS = 10;
const int MAXCOLS = 10;

// Typedefs
typedef float PriceType[MAXROWS][MAXCOLS];    // creates a new data type
											  // of a 2D array of floats
// Function Prototypes
void getPrices(PriceType&, int&, int&);	  // gets the prices into the array
void printPrices(PriceType, int, int);      // prints data as a table
float findHighestPrice(PriceType table, int numOfRows, int numOfCols);
float findLowestPrice(PriceType table, int numOfRows, int numOfCols);

int main() {
	int rowsUsed = 0;                               // holds the number of rows used 
    int colsUsed = 0;                               // holds the number of columns used
	PriceType priceTable;                       // a 2D array holding the prices
	float highest = 0;
	float lowest = 0;
	
	getPrices(priceTable, rowsUsed, colsUsed);  // calls getPrices to fill the array
	printPrices(priceTable, rowsUsed, colsUsed);// calls printPrices to display array
	
	highest = findHighestPrice(priceTable, rowsUsed, colsUsed);
	cout << "\nThe highest price in the 2d array is: " << highest;
	lowest = findLowestPrice(priceTable, rowsUsed, colsUsed);
	cout << "\nThe lowest price in the 2d array is: " << lowest;
	
	return 0;
}

//*********************************************************************************
//                           getPrices
//
//  task:     This procedure asks the user to input the number of rows and
//            columns. It then asks the user to input (rows * columns) number
//            of prices where x = rows * columns.  The data is placed in the array.
//  data in:  none
//  data out: an array filled with numbers and the number of rows 
//            and columns used.
//
//********************************************************************************
void   getPrices(PriceType &table, int& numOfRows, int& numOfCols) {
	cout << "Please input the number of rows from 1 to "<< MAXROWS << endl;
	cin >> numOfRows;

	cout << "Please input the number of columns from 1 to "<< MAXCOLS << endl;
	cin >> numOfCols;

	for(int row = 0;  row < numOfRows;  row++) {
		for(int col = 0; col < numOfCols;  col++) {
			cout << "\nPlease input the price of an item with 2 decimal places: ";
			cin  >> table[row][col];
		}
	}
}

//***************************************************************************
//                           printPrices
//
//  task:     This procedure prints the table of prices
//  data in:  an array of floating point numbers and the number of rows
//			  and columns used.
//  data out: none
//
//****************************************************************************
void   printPrices(PriceType table, int numOfRows, int numOfCols) {
	cout << fixed << showpoint << setprecision(2);

	for(int row = 0;  row < numOfRows; row++) {
		for(int col = 0;  col < numOfCols; col++)
			cout << setw(10) << table[row][col];
		cout << endl;
	}
}

float findHighestPrice(PriceType table, int numOfRows, int numOfCols)
// This function returns the highest price in the array
{
	float highestPrice;
	highestPrice = table[0][0]; // make first element the highest price for (int row = 0; row < numOfRows; row++)
	for (int row = 0; row < numOfRows; row++)
		for (int col = 0; col < numOfCols; col++)
			if ( highestPrice < table[row][col] )
				highestPrice = table[row][col];
			
return highestPrice;
}

float findLowestPrice(PriceType table, int numOfRows, int numOfCols)
// This function returns the lowest price in the array
{
	float lowestPrice;
	lowestPrice = table[0][0]; // make first element the lowest price for (int row = 0; row < numOfRows; row++)
	for (int row = 0; row < numOfRows; row++)
		for(int col = 0; col < numOfCols; col++)
			if(table[row][col] < lowestPrice)
				lowestPrice = table[row][col];
			
return lowestPrice;
}

// Because in order for print prices to get the correct data, the first function call
//  must pass its data by reference back to the main function so that the second function call
//  will have access to those values. If they were not reference then tehy would be destroyed when
//  the first function ends.

// When creating the lowest and highest function prototypes to output the lowest and highest value
//  of the 2d array. It outputs 102.34 for highest and 1.45 for the lowest.
