/*
 * Ryan Lockman
 * 101430670
 * pa2.cpp
 * Description: driver file for calculating shortest path algorithms
 *
*/ 

// Headers
#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>
#include "dijkstra.h"
#include "floydwarsh.h"
#include "pa2functions.h"

// Gobal COnstant
const float GRATUITY = 0.15, SHIRT = 60.00, MONEY = 77.90;

int main(int argc, char *argv[]) {
    // Check Arguments
    if(argc != 4 || strcmp(argv[1], "-h") == 0) {
        std::cout << "\nUsage: " << argv[0] << " [file path] [start vert] [end vert]"
                  << "\n\n*****Manpage*****"
                  << "\nCommands: -h"
                  << "\n[start vert] should be >= 0"
                  << "\n[end vert]   should be >= 0 and <= total verticies"
                  << "\n[file path]  should be correct path\n\n";
        return EXIT_FAILURE;
    }

    // Set Arguments
    int start = atoi(argv[2]);
    int end = atoi(argv[3]);

    // Check Argument Errors
    if(start <= 0 || end <= 0) {
        std::cerr << "\nError, type " << argv[0] << " -h \n for help\n\n";
        return EXIT_FAILURE;
    }

    // Output Welcome and Continue
    std::string ans;
    std::cout << "\n****************************************************************************************"
              << "\n***                                   Welcome!                                       ***"
              << "\n***This program is used to calculate the best path to a given verticy, along a route.***"
              << "\n***                               By: Ryan Lockman                                   ***"
              << "\n****************************************************************************************"
              << "\n\nContinue?: ";
    std::cin  >> ans;
    if(!promptYN(ans)) {
        std::cout << "\nGood-Bye!\n\n";
        return EXIT_SUCCESS;
    }

    // Initialize Classes
    Dijkstra<int, float> dijks;
    FloydWarsh<float> floyd;

    // Fill Matricies
    int ret = fillBothGraphs(dijks.getGraph(), floyd.getGraph(), argv[1]);
    if(ret == -1) {
		std::cerr << "\nError, opening file for reading.\n\n";
        return EXIT_FAILURE;
    }

    // Print Original Matrix
    std::cout << "\nOriginal Adjacency Matrix:\n";
    floyd.printFloydMatrix();

    // Calculate Floyd-Warshall
    floyd.calcFloydWarsh();

    // Print Calculated Matrix
    std::cout << "\nCalculated Adjacency Matrix:\n";
    floyd.printFloydMatrix();

    // Calculate Dijkstra
    dijks.calcDijkstra(start, end);

    // Print Shortest Path
    dijks.printPath();

    // Calculate Money
    std::cout << std::showpoint << std::fixed << std::setprecision(2)
              << "\nYour total bus fair is: $" << dijks.getTotalWeight()
              << "\nMoney left after bus fare: $" << MONEY-dijks.getTotalWeight();
    calcMoney(dijks.getTotalWeight(), SHIRT, GRATUITY, MONEY);
   
    std::cout << "\n\n";
    return 0;
}

