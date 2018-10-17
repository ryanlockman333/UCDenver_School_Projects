/********************************************************************************************* 
 * Ryan Lockman                                                                              *
 * pa4functions.h                                                                            *
 * Description: pa4functions prototypes.                                                     *
 * 3/28/14                                                                                   *
 *********************************************************************************************/

// Macro
#ifndef PA4FUNCTIONS_H
#define PAR4FUNTIONS_H

// Headers
#include <string>
#include "editor.h"

// Function Prototypes
bool promptYN(const std::string reply);
// Post: Returns true if user answers yes, false otherwise.
void line_remove(Editor &editor);
// Post: Removes line after in editor.
void nline_remove(Editor &editor);
// Post: Removes n line after in editor.
void insert(Editor &editor);
// Post: Inserts after in editor.
void ninsert(Editor &editor);
// Post: Inserts n after in editor.
void fremove(Editor &editor);
// Post: Removes first word in editor;
void aremove(Editor &editor);
// Post: Removes all word in editor.
void freplace(Editor &editor);
// Post: Replaces first word in editor.
void areplace(Editor &editor);
// Post: Replaces all word in editor.
void flush_stream();
// Post: Flushes the input stream.

#endif

