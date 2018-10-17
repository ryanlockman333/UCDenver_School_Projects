/********************************************************************************************* 
 * Ryan Lockman                                                                              *
 * pa5functions.h                                                                            *
 * Description: pa5functions prototypes.                                                     *
 * 4/16/14                                                                                   *
 *********************************************************************************************/

// Macro
#ifndef PA5FUNCTIONS_H
#define PA5FUNCTIONS_H

// Headers
#include <string>
#include <vector>

// Typedefs
typedef std::vector<std::vector<char> > Matrix;

// Function Prototypes
bool promptYN(const std::string reply);
// Post: Returns true if user answers yes, false otherwise.
void flush_stream();
// Post: Flushes the input stream.
template<class Frequencey> void fillMatrix(Frequencey fq);
// Post: Fills our Matrix for printing frequencey of occurence as star pattern.
template<typename OutStream> void printMatrix(const Matrix &myMatrix, OutStream &os);
// Post: Prints our Matrix in a star pattern to an Out Stream.

#include "pa5functions.tem"
#endif

