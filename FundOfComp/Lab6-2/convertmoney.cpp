// This program will input American money and convert it to foreign currency
// Ryan Lockman: 101430670

// Headers
#include <iostream>
#include <iomanip>
using namespace std;

// Global Constants
const float YEN   = 124.35;
const float EUROS = 1.06;
const float PESOS = 9.73;

// Function Prototypes
void  convertMulti(float dollars, float& euros, float& pesos);
void  convertMulti(float dollars, float& euros, float& pesos, float& yen);
float convertToYen(float dollars);
float convertToEuros(float dollars);
float convertToPesos(float dollars);

int main () {
	float dollars = 0;
	float euros	  = 0;
	float pesos   = 0;
	float yen     = 0;
	
	cout << fixed << showpoint << setprecision(2);
	cout << "Please input the amount of American Dollars you want converted\n"
		 << "to euros and pesos: ";
	cin  >> dollars;
	convertMulti(dollars, euros, pesos);
	cout << "\nThe dollars converted to euros is $" << euros
	     << "\nand converted to pesos is $" << pesos;
	
	cout << "\n\n\n\nPlease input the amount of American Dollars you want converted\n"
	     << "to euros, pesos, and yen: ";
	cin  >> dollars;
	convertMulti(dollars, euros, pesos, yen);
	cout << "\nThe dollars converted to euros is $" << euros
		 << "\nand converted to pesos is $" << pesos
		 << "\nand converted to yen is $" << yen;
	
	cout << "\n\n\n\nPlease input the amount of American Dollars you want converted\n"
	     << "to yen: ";
	cin  >> dollars;
	yen = convertToYen(dollars);
	cout << "\nThe dollars converted to yen is $" << yen;
	
	cout << "\n\n\n\nPlease input the amount of American Dollars you want converted\n"
	     << "to euros :";
	cin  >> dollars;
	euros = convertToEuros(dollars);
	cout << "\nThe dollars converted to euros is $" << euros;	
	
	cout << "\n\n\n\nPlease input the amount of American Dollars you want converted\n"
	     << "to pesos: ";
	cin  >> dollars;
	pesos = convertToPesos(dollars);
	cout << "\n\nThe dollars converted to pesos is $" << pesos;	
	
	return 0;
}

//  ************************************************************************
//                           convertMult
//                           
//   task:     This function takes a dollar value and converts it to euros
//             and pesos
//   data in:  dollars
//   data out: euros and pesos
//
//   ***********************************************************************
void  convertMulti(float dollars, float& euros, float& pesos) {  
	cout << "\nThe function convertMulti with dollars, euros and pesos "
		 << endl <<" was called with " << dollars <<" dollars\n";
		 
	euros = convertToEuros(dollars);
	pesos = convertToPesos(dollars);
}

//  ************************************************************************
//                           convertMult
//                           
//   task:     This function takes a dollar value and converts it to euros
//             pesos and yen
//   data in:  dollars
//   data out: euros pesos yen
//
//   ***********************************************************************

void  convertMulti(float dollars, float& euros, float& pesos, float& yen) {
	cout << "\nThe function convertMulti with dollars, euros, pesos and yen"
		 << endl << " was called with " << dollars << " dollars\n";
		 
	euros = convertToEuros(dollars);
	pesos = convertToPesos(dollars);
	yen   = convertToYen(dollars);
}

//  ****************************************************************************
//                           convertToYen
//                           
//   task:          This function takes a dollar value and converts it to yen
//   data in:       dollars
//   data returned: yen
//
//   ***************************************************************************

float convertToYen(float dollars) {
	cout << "\nThe function convertToYen was called with " << dollars <<" dollars\n";
	return (dollars * YEN);
}

//  ****************************************************************************
//                           convertToEuros
//                           
//   task:          This function takes a dollar value and converts it to euros
//   data in:       dollars
//   data returned: euros 
//
//   ***************************************************************************
float convertToEuros(float dollars) {
	cout << "\nThe function convertToEuros was called with " << dollars << " dollars\n";
	return (dollars * EUROS);
}

//  *****************************************************************************
//                           convertToPesos
//                           
//   task:          This function takes a dollar value and converts it to pesos       
//   data in:       dollars
//   data returned: pesos
//
//   ****************************************************************************
float convertToPesos(float dollars) {
	cout << "\nThe function convertToPesos was called with " << dollars << " dollars\n";
    return (dollars * PESOS);
}
