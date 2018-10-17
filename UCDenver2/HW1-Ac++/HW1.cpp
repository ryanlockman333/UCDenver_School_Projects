/* 
 * Ryan Lockman
 * Homework 1
 * CSCI 3320
 * ./HW1.cpp driver file
 * Description: Calculates interpolating polynomials via the lagrange method.
 *
*/

// Headers
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <vector>
#include <iomanip>
#include <cassert>
#include "hw1functions.h"

int main(int argc, char *argv[]) {
    // Declarations
    std::vector<float> x, y;
    float pos = 0;
    std::string ans;
    
    // Check Arguments
    if(argc != 2 || strcmp(argv[1], "-h") == 0) {
        std::cout << "\nUsage: " << argv[0] << " [file path]\n\n";
        return EXIT_FAILURE;
    }

    // Fill Array from File
    int retDegree = fillArray(argv[1], x, y);
    if(retDegree == -1) {
		std::cerr << "\nError, opening file for reading.\n\n";
        return EXIT_FAILURE;
    }

    // Output Welcome and Continue
    std::cout << "\nWelcome!"
              << "\nThis program calculates an interpolating polynomial to the desired x.\n"
              << "\nContinue?: ";
    std::cin  >> ans;
    if(!promptYN(ans))
        return EXIT_SUCCESS;

    // Input Position
    std::cout << "\nPlease, enter the desired X value:  ";
    std::cin  >> pos;

    // Interpolate via Lagrange and Outpt Function
    float fx = interpolatePoly(x, y, retDegree, pos);

    // Calculate Interpolation
    std::cout << std::fixed << std::showpoint << std::setprecision(1)
              << "\nP(" << pos << ") = " << fx << "\n\n"; 

    return 0;
}

