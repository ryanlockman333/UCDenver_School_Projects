/******************************************************************************************************
 * Ryan Lockman                                                                                       *
 * 101430670                                                                                          *
 * pa5.cpp driver file                                                                                *
 * Description: This program reads a file from argv[1] and outputs a concordance of that file to      *
 *              argv[2]. Then it reads from argv[1] again and makes a frequencey of occurence for     *
 *              the letters and outputs them to argv[3]. Then we print the frequencey of occurence    *
 *              as a star* patter to the standard output.                                             *
 * 4/16/14                                                                                            *
 ******************************************************************************************************/

// Headers
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include "pa5functions.h"
#include "concordance.h"
#include "freq_occur.h"

// Function Prototypes
void help_menu();

int main(int argc, char *argv[]) {
    // Check Arguments
    if(argc != 4 || strcmp(argv[1], "-h") == 0) {
        std::cout << "\nUsage: " << argv[0] << " [inFile path] [outFile path] [outFile path]\n\n";
        return EXIT_FAILURE;
    }

    // Set Arguments
    const char* const INPATH  = argv[1];
    const char* const CONPATH = argv[2];
    const char* const FQPATH  = argv[3];

    // Output Welcome and Continue
    std::string ans;
    std::cout << "\n**************************************************************************"
              << "\n***                             Welcome!                               ***"
              << "\n***                                                                    ***"
              << "\n***  This program reads a file from argv[1] and outputs a concordance  ***" 
              << "\n***   of that file to argv[2]. Then it reads from argv[1] again and    ***"
              << "\n***  makes a frequencey of occurence for the letters and outputs them  ***"
              << "\n***  to argv[3]. Then we print the frequencey of occurence again as a  ***"
              << "\n***               star* patter to the standard output.                 ***"
              << "\n***                                                                    ***"
              << "\n***                         By: Ryan Lockman                           ***"
              << "\n**************************************************************************"
              << "\n\nContinue?: ";
    std::cin  >> ans;
    if(!promptYN(ans)) {
        std::cout << "\nGood-Bye!\n\n";
        return 0;
    }
    std::cout << "\nProcessing..........\n";

    // Declarations
    Concordance concord;
    Freq_Occur fq;

    // Input Concordance
    if(concord.fin_concord(INPATH) == -1) {
        std::cerr << "Error, opening file for reading.";
        return EXIT_FAILURE;
    }

    // Output Concordance
    if(concord.fout_concord(CONPATH) == -1) {
        std::cerr << "Error, opening file for writing.";
        return EXIT_FAILURE;
    }

    // Input Frequencey of Occurence
    if(fq.fin_occur(INPATH, std::string("`1234567890-=~!@#$%^&*()_+[]\\{}|;\':\",./<>?")) == -1) {
        std::cerr << "Error, opening file for reading.";
        return EXIT_FAILURE;
    }

    // Output Frequency of Occurence
    if(fq.fout_occur(FQPATH) == -1) {
        std::cerr << "Error, opening file for writing.";
        return EXIT_FAILURE;
    }

    // Fill and Print * Matrix to Standard Output
    fillMatrix(fq);

    std::cout << "\n\nDone, please check you files.\n\n";
    return EXIT_SUCCESS;
}

