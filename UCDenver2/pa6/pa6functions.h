/********************************************************************************************************
 * Ryan Lockman                                                                                         *
 * pa6functions.h                                                                                       *
 * Description: pa6 function prototypes.                                                                *
 * 5/7/14                                                                                               *
 ********************************************************************************************************/

// Macro
#ifndef PA6FUNCTIONS_H
#define PA6FUNCTIONS_H

// Headers
#include <string>
#include "set.h"

// Global Function Prototypes
template<typename set_T>
int readFile(const char* const path, set_T &s1, set_T &s2, set_T &s3);
// Pre:  File path must be correct path
// Post: Fills Set data structures from specified file, returns 0 on success, -1 on error
bool promptYN(const std::string reply);
// Post: Returns true if user answers yes, false otherwise.
void flush_stream();
// Post: Flushes the input stream.

#include "pa6functions.tem"
#endif

