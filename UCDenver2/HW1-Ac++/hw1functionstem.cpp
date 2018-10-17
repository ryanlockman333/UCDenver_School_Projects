/* 
 * Ryan Lockman
 * Homework 1
 * CSCI 3320
 * ./hw1functions.tem
 * Description: hw1functions implementations
 *
*/ 

// Headers
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>

template <typename Container>
int fillArray(const char *path, Container &x, Container &y) {
    std::ifstream inFile(path);
	if(!inFile)
        return -1;

    std::string str;
    unsigned used = 0;
    while(inFile.good() && inFile.peek() != EOF) {
        std::getline(inFile, str, ' ');
        x.push_back(atof(str.c_str()));
        std::getline(inFile, str, '\n');
        y.push_back(atof(str.c_str()));
        ++used;
    }

    return used;
}

template<typename Container>
void printContainers(const Container &x, const Container &y) {
    typename Container::const_iterator citX = x.begin(), citY = y.begin();

    for(; citX != x.end() && citY != y.end(); ++citX, ++citY)
        std::cout << "\n(" << *citX << ", " << *citY << ")";
}

template<typename Type, typename Container>
Type interpolatePoly(const Container &x, const Container &y, const unsigned degree, const Type fx) { 
    Type retVal = 0, weight = 1;
    std::stringstream ss;
    std::string str, str2, formula, final;

    // Initialize Final Formual
    ss << "P" << degree << "(x)=";
    ss >> final;
    ss.clear();
 
    // Lagrange Algorithm
    for(unsigned i = 0; i < degree; ++i, weight = 1) { 
        for(unsigned j = 0; j < degree; ++j)
            if(j != i) {
                weight *= (fx - x.at(j)) / (x.at(i) - x.at(j)); // calculation
               
                // Check to Subtract - for Formatted Output
                if(x.at(j) < 0)
                    ss << "(x+" << x.at(j) << ")/(" << x.at(i) << "+" << x.at(j) << ")";
                else
                    ss << "(x-" << x.at(j) << ")/(" << x.at(i) << "-" << x.at(j) << ")";
  
                // Add Output to Formual
                ss >> str;
                formula += str + " ";
                ss.clear();
            }

        // Check To Add + for Formated Output
        if(&(y.at(i)) != &(y.at(0)) && y.at(i) > 0)
            ss << "+" << y.at(i) << str;    
        else
            ss << y.at(i) << str;

        // Add Output to Final Formual
        ss >> str2;
        final += str2;
        ss.clear();

        retVal += weight * y.at(i); // calculation
    } 
 
    // Output Formual
    std::cout << "\n" << final << "\n";

    return retVal; 
}

bool promptYN(const std::string reply) {
	if	   (reply == "YES"		 || reply == "Yes"		 || reply == "yes"		 ||
		    reply == "SURE"		 || reply == "Sure"		 || reply == "sure"		 ||
		    reply == "OK"		 || reply == "Ok"		 || reply == "ok"		 ||
		    reply == "Y"		 || reply == "y")
		    return true;
	else if(reply == "NO"        || reply == "No"		 || reply == "no"		 ||
		    reply == "QUIT"      || reply == "Quit"		 || reply == "quit"		 ||
			reply == "STOP"      || reply == "Stop"		 || reply == "stop"		 ||
			reply == "TERMINATE" || reply == "Terminate" || reply == "terminate" ||
			reply == "N"		 || reply == "n")
			return false;
	else
			return false;
}

