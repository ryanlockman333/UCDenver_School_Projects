/********************************************************************************************* 
 * Ryan Lockman                                                                              *
 * editor.h                                                                                  *
 * Description: Editor Class prototypes for a command line text editor.                      *
 * 3/31/14                                                                                   *
 *********************************************************************************************/

// Macro
#ifndef EDITOR_H
#define EDITOR_H

// Headers
#include <cstdlib>
#include <string>
#include "forward_list.h"

// Editor Class
class Editor {
public:
    // Typedefs
    typedef std::string value_type;
    typedef std::size_t size_type;

    // Constructors
    explicit Editor(const Forward_List<value_type> &data = Forward_List<value_type>()) : list(data) {}
    // Post: Initializzes data members.

    // Modification Members
    void out_after_line(const unsigned line);
    // Pre:  Line should be > 0 and < size()-1.
    // Post: Deletes line after specified line.
    void nout_after_line(const unsigned line, unsigned n);
    // Pre:  Line should be > 0 and < size()-1.
    // Post: Deletes n lines after specified line.
    void in_after_line(const unsigned line, const std::string insert);
    // Pre:  Line should be > 0 and < size().
    // Post: Inserts specified string after specified line.
    void nin_after_line(const unsigned line, const Forward_List<value_type> &insert);
    // Pre:  Line should be > 0 and < size().
    // Post: Inserts specified list of strings after specified line.
    bool remove_first(const std::string word);
    // Post: Removes first occurence of specified word, returns true if there, false otherwise.
    void remove_all(const std::string word);
    // Post: Removes all occurences of specified word.
    bool replace_first(const std::string word, const std::string replace);
    // Post Replaces first occurence of specified word with specified replace, returns true if there,
    //      false otherwise.
    void replace_all(const std::string word, const std::string replace);
    // Post: Replaces all occurences of specified word wiht specified replace.
    int fill_editor(const char* const path);
    // Pre:  Path must be the correct pathname to specified file.
    // Pst:  Fills list and returns 0 if succeeded, -1 if it doesn't succeed.
    int save_editor(const char* const path);
    // pre:  Path must be correct pathname to specified file.
    // Post: Saves list and returns 0 if succeeded, -1 if it doesn't succeed.
    void clear_screen();
    // Post: Clears the terminal screen safely, and is portable.

    // Constant Members
    size_type lines() const { return list.size(); }
    // Post: Returns size of editor(total line).
    bool empty() const { return list.empty(); }
    // Post: Returns ture if editor is empty, false otherwise.
    void print() const;
    // Post: Prints the editor's document to the terminal.

private:
    // Data Members
    Forward_List<std::string> list;

    // Helper Functions
    typename Forward_List<value_type>::iterator pos_iter(const unsigned line);
    typename Forward_List<value_type>::const_iterator pos_const_iter(const unsigned line) const;
};

#endif

