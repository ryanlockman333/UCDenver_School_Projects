/* 
 * Ryan Lockman
 * PA2functions.h
 * Description: pa2 function prototypes
 *
*/  

/*
// Pre/Post Conditions
int fillBothGraphs(DijksGraph &G1, FloydGraph &G2, const char *path);
Pre:  DijksGraph and FloydGraph containers must be a vector of vectors and data file
      must be correct path.
Post: Returns 0 and fills graphs on success otherwise returns -1 if wrong file provided.

void calcMoney(const T busFare, const float productCosts, const float gratuity, const float currentMoney);
Pre:  All parameters should be >= 0.
Post: Prints out what food a user can order.

bool promptYN(const std::string reply);
Post: Returns true or false based on the user's answer.
*/

#ifndef PA2FUNCTIONS_H
#define PA2FUNCTIONS_H

// Headers
#include <string>

template<class DijksGraph, class FloydGraph>
int fillBothGraphs(DijksGraph &G1, FloydGraph &G2, const char *path);

template<typename T>
void calcMoney(const T busFare, const float productCosts, const float gratuity, const float currentMoney);

bool promptYN(const std::string reply);

#include "pa2functions.tem"
#endif

