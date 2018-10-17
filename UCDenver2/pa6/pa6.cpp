/************************************************************************************************************
 * Ryan Lockman                                                                                             *
 * pa6.cpp - Driver File                                                                                    *
 * Description: This program calculates the binomial theorem in its first part and reads data in from a     *
 *              file and stores them in 3 Set data structures to perform Union, Intersection, and           *
 *              Difference operations on them in its second part.                                           *
 * Compiler: Uses c++11                                                                                     *
 * 5/7/14                                                                                                   *
*************************************************************************************************************/

// Headers
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <iterator>
#include <algorithm>
#include "set.h"
#include "bin_coeff.h"
#include "pa6functions.h"

int main(int argc, char *argv[]) {	
    // Check Arguments
    if(argc != 3 || std::atoi(argv[2]) < 0 || std::atoi(argv[2]) > 10 || std::strcmp(argv[1], "-h") == 0) {
        std::cerr << "\nUsage:     " << argv[0] << " [inFile path] [N]"
                  << "\nSemantics: N >= 0 and N <= 10\n\n";
        return EXIT_FAILURE;
    }	

    // Set Arguments
    const char* const PATH = argv[1];
    const unsigned long N  = std::atol(argv[2]);

    // Output Welcome and Continue
    std::string ans;
    std::cout << "\n***************************************************************************"
              << "\n***                             Welcome!                                ***"
              << "\n***   The first part of this program calculates the binomial theorem    ***"
              << "\n***  based on the N value given to argv[2] and displays its associated  ***"
              << "\n***                              tuple.                                 ***"
              << "\n***    The second part of this program reads data in from a file and    ***"
              << "\n***        stores them in 3 Set data structures to perform Union,       ***"
              << "\n***           Intersection, and Difference operations on them.          ***"
              << "\n***                         By: Ryan Lockman                            ***"
              << "\n***************************************************************************"
              << "\n\nContinue?: ";
    std::cin  >> ans;
    if(!promptYN(ans)) {
        std::cout << "\n\nGood-Bye!\n\n";
        return EXIT_SUCCESS;
    }
    std::cout << std::endl;

 // Part 1:
/***********************************************************************************************************/

    // Declarations for Part1
    Bin_Coeff<> Bin;
    
    // Calculate Bionomial Coeffs via Pascal
    Bin.pascal(N);

    // Print Bionomial Coeff
    std::cout << "\nExpansion Expression: (a + b)^n" << std::endl;
    Bin.print();

 // Part 2:
/***********************************************************************************************************/

    // Prompt to Coninue
    std::cout << "\nContinue with Part 2 (Set Opperation Calculations)?: ";
    std::cin  >> ans;
    if(!promptYN(ans)) {
        std::cout << "\nGood-Bye!\n\n";
        return EXIT_SUCCESS;
    }

    // Declarations for Part2
    Set<float> A, B, C;

    // Read File
    if(readFile(PATH, A, B, C) == -1) {
		std::cerr << "\nError, opening file for reading.\n";
        return EXIT_FAILURE;
    }

    // Calculations
	std::cout << "\nA = {" << A;
	std::cout << "}";
	std::cout << "\nB = {" << B;
	std::cout << "}";
	std::cout << "\nC = {" << C;
	std::cout << "}\n";

    // 1st
	std::cout << "\n A       ∩  (B ∪ C)  =  {";
	Set<float> calc1 = A & (B | C);
	std::cout << calc1;
	std::cout << "}";

    // 2nd
	std::cout << "\n(A ∪ B)  -   C       =  {";
	Set<float> calc2 = (A | B) - C;
	std::cout << calc2;
	std::cout << "}";
	
    // 3rd
	std::cout << "\n(A ∩ B)  ∪  (B ∩ C)  =  {";
	Set<float> calc3 = (A & B) | (B & C);
	std::cout << calc3;
	std::cout << "}";
	
    // 4th
	std::cout << "\n(A - B)  ∪  (C - A)  =  {";
	Set<float> calc4 = (A - B) | (C - A);
	std::cout << calc4;
	std::cout << "}";
	
    // 5th
	std::cout << "\n(A ∩ B) ==  (B - C)  =  ";
	if((A & B) == (B - C))
		std::cout << std::boolalpha << true;
	else
		std::cout << std::boolalpha << false;

	std::cout << '\n' << std::endl; // flush through endl
	return EXIT_SUCCESS;
}

