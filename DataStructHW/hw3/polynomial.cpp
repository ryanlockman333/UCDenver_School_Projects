/*
Ryan Lockman: 101430670
CSCI 2421:001 Fall 2013
polynomial.cpp
Description: Polynomial class definitions.
*/

// Headers
#include "polynomial.h"

// Set Member Functions
void polynomial::setCoef(const int posIn, const int coefIn) {
	assert(posIn > 0 && posIn <= getUsed());
	data[posIn-1] = coefIn;
}

// Get Member Functions
int polynomial::getCoef(const int posIn) const {
	assert(posIn > 0 && posIn <= getUsed());
	return data[posIn-1];
}

// Other Member Functions
int polynomial::evaluateAt(int x) {
    int result = data[getUsed()-1];
    for(int i = getUsed()-1; i >= 0; --i)
      result = result * x + data[i];
	  
    return result;
}

void polynomial::readFile(const std::string fileName, const int fileLine) {
	char c = '\0';
	int intToAdd = 0;
	std::ifstream inFile(fileName.c_str());	
	if(!inFile) {
		std::cout << "\nError opening file for reading\n";
		return;
	}

	if(fileLine == 1)
		while(inFile.good())
			if(inFile.peek() == '\n' || inFile.peek() == '\r')
				return(inFile.close());
			else {
				inFile >> c;
				intToAdd = c-48;
				alloc(intToAdd);
			}
	else if(fileLine == 2)
		while(inFile.good()) {
			if(inFile.peek() == '\n' || inFile.peek() == '\r')
				while(inFile >> c) {
					intToAdd = c-48;
					alloc(intToAdd);
				}
			inFile >> c;
		}
			
	inFile.close();
}

// Stream Operators
std::ostream& operator<<(std::ostream &os, const polynomial &rhs) {
	os << " (";
	for(int i = 0; i < rhs.getUsed(); i++)
		if(i == rhs.getUsed()-1)
			os << rhs.getCoef(i+1) << ")";
		else
			os << rhs.getCoef(i+1) << ", ";
	os << "\n";
  return os;
}

// Arithmetic Operators
polynomial polynomial::operator+(const polynomial &rhs) const {
	polynomial tmpPoly;
	
	for(int i = 0; i < getUsed(); i++)
		tmpPoly.alloc(getCoef(i+1) + rhs.getCoef(i+1));
		
	return tmpPoly;
}

polynomial polynomial::operator*(const polynomial &rhs) const {
	polynomial tmpPoly;
	
	//for(int i = 0; i < getUsed(); i++)
		//tmpPoly.alloc(data[i] * 
}

// Private Functions
void polynomial::alloc(const int intIn) {
	int *tmpData = new int[getUsed()+1];
	
	for(int i = 0; i < getUsed(); i++)
		tmpData[i] = data[i];
	tmpData[getUsed()] = intIn;
	used++;
	delete [] data;
	data = tmpData;
}

void polynomial::free() {
	delete [] data;
	data = NULL;
}