/*
This program will find allow the user to input the temperature for a certain
amount of days. The program will then compute the average, highest, and lowest
of the entered temperatures.
Ryan Lockman: 101430670
*/

// Headers
#include <iostream>
#include <iomanip>

// Typedefs
typedef int tempArray[50];

// Function Prototypes
float findAverage(const tempArray array, int size);
float findHighest(const tempArray array, int size);
float findLowest (const tempArray array, int size);

int main() {
	// Declarations
	tempArray temps;
	float low = 0, high = 0, avg = 0;
	int pos = 0, days = 0;
	
	std::cout << "\nPlease enter in the number of temperatures to be read: ";
	std::cin  >> days;
	
	while(pos < days) {
		std::cout << "\nPlease enter in the temperature for day " << pos+1 << ": ";
		std::cin  >> temps[pos];
		++pos;
	}

	std::cout << std::fixed << std::showpoint << std::setprecision(2);
	avg = findAverage(temps, pos);
	low = findLowest(temps, pos);
	high = findHighest(temps, pos);
	
	std::cout << "\nThe average temperature for the last " << days << " days: " << avg  << " degrees";
	std::cout << "\nThe lowest temperature for the last "  << days << " days:  " << low << " degrees";
	std::cout << "\nThe highest temperature for the last " << days << " days: " << high << " degrees";

	return 0;
}

float findAverage(const tempArray array, int size) {
	float sum = 0;
	
    for(int pos = 0; pos < size; pos++)	
	   sum = sum + array[pos];

    return (sum / size);
}

float findHighest(const tempArray array, int size) {
	float highest = 0;

	for(int pos = 0; pos < size; ++pos)
		if(array[pos] > highest)
			highest = array[pos];
			
	return highest;
}

float findLowest (const tempArray array , int size) {
	float lowest = array[0];

	for(int pos = 0; pos < size; ++pos)
		if(array[pos] < lowest)
			lowest = array[pos];
			
	return lowest;
}
