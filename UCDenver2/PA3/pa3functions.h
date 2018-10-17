/* 
 * Ryan Lockman
 * pa3functions.h
 * Description: PA3 function prototypes
 * 3/17/14
 *
*/

// Macro
#ifndef PA3FUNCTIONS_H
#define PA3FUNCTIONS_H

// Headers
#include <string>

// Function Prototypes
bool promptYN(const std::string reply);
// Post: Return true if user answers yes, false for no.
float computeDues(const float hours);
// Post: Returns calculated dues for a member.

// Template Function Prototypes
template<class HashTable>
int fillTable(HashTable &table, const char *path);
// Pre:  path must be correct location.
// Post: Returns -1 if data can't be pushed into table(overflow), or -1
//       if if path is wrong. Otherwise fills the specified table.

template<class HashTable>
void printTableStats(const HashTable &table);
// Post: Prints Table's Record's data in formated output.

#include "pa3functions.tem"
#endif

