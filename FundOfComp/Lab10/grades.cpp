// Ryan Lockman: 101430670

// Headers
#include <fstream>
#include <iostream>

// Global Constants
const int MAXNAME = 20;

int main() {
	char  name[MAXNAME + 1];  // holds student name
	float average = 0;        // holds student average
	
	std::ifstream inData("grades.txt");
	if(!inData) {
		std::cout << "\nError opening file for reading.\n";
		return 1;
	}

	std::cout << "\n           OUTPUT TO SCREEN\n";
	inData.get(name, MAXNAME+1);
	while(inData.good()) {
		inData >> average;
		std::cout << "\n" << name << "has a(n) " << average << " average";
	
		inData.ignore(10, '\n');
		inData.get(name, MAXNAME+1);	
	}
	
	inData.close();
	
	return 0;
}
