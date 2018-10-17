/* 
 * Ryan Lockman
 * Homework 1
 * CSCI 3320
 * ./hw1functions.h
 * Description: hw1functions prototypes
 *
*/  

/* 
// Pre/Post Conditions:
fillArray(const char *path Container &x, Container &y);
 Pre:  Container types must have push_back() member, either user defined or STLs.
       The file path must also be correct.
 Post: Return value is set to -1 for file path error, otherwise it returns the degree. 

void printContainers(const Container &x, const Container &y);
 Pre:  Container type must have a const_iterator, either user defined or STLs.
 Post: Containers are printed in the correct format (x, y).

Type interpolatePoly(Container x, Container y, unsigned degree, Type fx);
 Pre:  Container types must have the .at(index) member, either user defined or STLs.
       Container's values must be able to use arithmetic.  
 Post: Return value is the calculatin via the Lagrange interpolation method.

bool promptYN(const std::string reply);
 Post: The return value is either true or false depending on the user's reply.
*/

// Headers
#include <string>

template<typename Container>
int fillArray(const char *path, Container &x, Container &y);

template<typename Container>
void printContainers(const Container &x, const Container &y);

template<typename Type, typename Container>
Type interpolatePoly(const Container &x, const Container &y, const unsigned degree, const Type fx);

bool promptYN(const std::string reply);

#include "hw1functionstem.cpp"

