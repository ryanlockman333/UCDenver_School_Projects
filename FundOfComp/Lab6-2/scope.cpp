// This program will demonstrate the scope rules.
// Ryan Lockman: 101430670

// Headers
#include <iostream>
#include <iomanip>
#include <cmath>

// Constants
const double PI   = 3.14;
const double RATE = 0.25;

// Function Prototypes
void findArea(float, float&);
void findCircum(float, float&);

int main() {
	std::cout << std::fixed << std::showpoint << std::setprecision(2);
	float radius = 12;
	
	std::cout << "Main function outer block\n";
    std::cout << "PI, RATE, and radius are active here\n\n";
	
	{
		float area = 0;
		
        std::cout << "Main function first inner block\n";	
		std::cout << "PI, RATE, radius(outer), and area are active here\n\n";
		
		findArea(radius, area);
		
		std::cout << "The radius = " << radius << std::endl;
		std::cout << "The area   = " << area << std::endl << std::endl;
	}
	{
        float radius 		= 10;
		float circumference = 0;
		
		std::cout << "Main function second inner block\n";
		std::cout << "PI, RATE, radius(inner/outer), and circumference are active here\n\n";
		
		findCircum(radius, circumference);
		
		std::cout << "The radius        = " << radius << std::endl;
		std::cout << "The circumference = " << circumference << std::endl << std::endl;
	}
	
	std::cout << "Main function after all the calls\n";
	std::cout << "PI, RATE, and radius are active here\n\n";
	   
	return 0;
}

//  *********************************************************************
//                           findArea
//   
//   task:     This function finds the area of a circle given its radius
//   data in:  radius of a circle
//   data out: answer (which alters the corresponding actual parameter)
//
//   ********************************************************************
void findArea(float rad, float& answer) {
	
    std::cout << "AREA FUNCTION\n\n";
	std::cout << "PI, RATE, rad, and answer are active here\n\n";
	
	answer = PI * pow(rad, 2);
}

//  ******************************************************************************
//                           findCircumference
//   
//   task:     This function finds the circumference of a circle given its radius
//   data in:  radius of a circle
//   data out: distance (which alters the corresponding actual parameter)
//
//   *****************************************************************************
void findCircum(float length, float& distance) {
	std::cout << "CIRCUMFERENCE FUNCTION\n\n";
	std::cout << "PI, RATE, length, and distance are active here\n\n";
	
	distance = 2 * PI * length;
}

/*
GLOBAL		MAIN		 MAIN(Inner One)		MAIN(Inner Two)		AREA		 CIRCUMFERENCE
PI			PI			 PI						PI					PI			 PI
RATE		RATE		 RATE					RATE				RATE		 RATE
			radius		 radius(outer)	        radius(inner/outer) rad			 length
			findArea()	 area				    circumference		answer		 distance
			findCircum() findArea()			    findArea()			findCircum() findArea()
					     findCircum()			findCircum()
Recursion would allow findArea() and findCircum() to be called within their functions
*/
// I expect the output to be right, if the correct formulas have been used
// The outer radius will be passed in for the first block because during the call the function will
//  look in its scope first, since nothing is their, it moves to the main function
//  and finds it their.
// The radius for second inner block will be passed, because its in its scope(block)
