/****************************************************************************************************
 * Ryan Lockman                                                                                     *
 * 101430670                                                                                        *
 * pa3.cpp                                                                                          *
 * Driver File                                                                                      *
 * Description: This program calculates the dues for each person through the use of a hash table.   *
 * 3/17/14                                                                                          *
 *****************************************************************************************************/

// Headers
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include "record.h"
#include "table.h"
#include "pa3functions.h"

int main(int argc, char *argv[]) {
    // Check Arguments
    if(argc != 2 || strcmp(argv[1], "-h") == 0) {
        std::cout << "\nUsage: " << argv[0] << " [file path]\n\n";
        return EXIT_FAILURE;
    }

    // Output Welcome and Continue
    std::string ans;
    std::cout << "\n*****************************************************************************"
              << "\n***                            Welcome!                                   ***"
              << "\n***       This program lists the total dues by month for a member.        ***"
              << "\n***                        By: Ryan Lockman                               ***"
              << "\n*****************************************************************************"
              << "\n\nContinue?: ";
    std::cin  >> ans;
    if(!promptYN(ans)) {
        std::cout << "\nGood-Bye!\n\n";
        return 0;
    }

    // Declarations
    Table<Record> table;

    // Fill Table
    if(fillTable(table, argv[1]) == -1)
        return EXIT_FAILURE;

    // Print Table Stats
    printTableStats(table);
    std::cout << std::endl;

    return EXIT_SUCCESS;
}

