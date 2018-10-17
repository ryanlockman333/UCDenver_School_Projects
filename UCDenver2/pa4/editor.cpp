/********************************************************************************************* 
 * Ryan Lockman                                                                              *
 * editor.cpp                                                                                *
 * Description: Editor Class implementations for command-line text editor.                   *
 * 3/31/14                                                                                   *
 *********************************************************************************************/

// Headers
#include <fstream>
#include <iostream>
#include "editor.h"

// Modification Members
void Editor::out_after_line(const unsigned line) {
    // Check Line
    if(line <= 0 || line > list.size()-1)
        return;
    
    // Position Iterator
    typename Forward_List<value_type>::iterator pos = pos_iter(line), e = list.end();
    
    // Erase After Iterator
    if(pos != e)
        list.remove_after(pos);
}

void Editor::nout_after_line(const unsigned line, const unsigned n) {
    // Check Line
    if(line <= 0 || line > list.size()-1)
        return;

    // Loop Deletes
    unsigned i = 0;
    while(i++ < n)
        out_after_line(line);
}

void Editor::in_after_line(const unsigned line, const std::string insert) {
    // Check Line
    if(line <= 0 || line > list.size())
        return;

    // Position Iterator
    typename Forward_List<value_type>::iterator pos = pos_iter(line), e = list.end();
    
    // Insert After Itertaor
    if(pos != e)
        list.insert_after(pos, insert);
}

void Editor::nin_after_line(const unsigned line, const Forward_List<value_type> &insert) {
    // Check Line
    if(line <= 0 || line > list.size())
        return;

    // Position Iterator
    typename Forward_List<value_type>::iterator pos = pos_iter(line), le = list.end();

    // Set Up Iterator Range
    typename Forward_List<value_type>::const_iterator ib = insert.cbegin(), ie = insert.cend();
    
    // Insert N Lines After iterator
    if(pos != le)
        list.insert_after(pos, ib, ie);

    // Less Code, also works
    /*while(b != e)
       in_after_line(line, *b++);*/
}

bool Editor::remove_first(const std::string word) {
    // Loop List
    typename Forward_List<value_type>::iterator b = list.begin(), e = list.end();
    while(b != e) {
        std::size_t found = b->find(word); // find
        if(found != std::string::npos) {
            b->erase(found, word.length()); // erase if found
            return true;
        }
        else
            ++b;
    }
    return false;
}

void Editor::remove_all(const std::string word) {
    while(remove_first(word));
}

bool Editor::replace_first(const std::string word, const std::string replace) {
    // Loop List
    typename Forward_List<value_type>::iterator b = list.begin(), e = list.end();
    while(b != e) {
        std::size_t found = b->find(word); // find
        if(found != std::string::npos) {
            b->replace(found, word.length(), replace); // replace if found
            return true;
        }
        else
            ++b;
    }
    return false;
}

void Editor::replace_all(const std::string word, const std::string replace) {
    while(replace_first(word, replace));
}

int Editor::fill_editor(const char* const path) {
    // Open File
    std::ifstream ifs(path);
    if(!ifs) {
        std::cerr << "\nError, openning file for reading.\n";
        return -1;
    }
    
    // Fill Reverse for Correct Order
    Forward_List<std::string> reverse;
    std::string buf;
    while(ifs.good() && ifs.peek() != EOF) {
        std::getline(ifs, buf, '\n');
        reverse.push_front(buf);
    }
    ifs.close();

    // Fill Actual List
    while(!reverse.empty()) {
        list.push_front(reverse.front());
        reverse.pop_front();
    }

    return 0;
}

int Editor::save_editor(const char* const path) {
    // Open File
    std::ofstream ofs(path);
    if(!ofs) {
        std::cerr << "\nError, opening file for writing.\n";
        return -1;
    }

    // Loop Out Data
    typename Forward_List<value_type>::const_iterator b = list.cbegin(), e = list.cend();
    while(b != e)
        ofs << *b++ << "\n";

    ofs.close();
    return 0;
}

void Editor::clear_screen() {
    // Portable, Safe
    std::cout << std::string(100, '\n');
}

// Constant Members
void Editor::print() const {
    if(!empty()) {
        unsigned count = 0;       
        typename Forward_List<value_type>::const_iterator b = list.cbegin(), e = list.cend();
        while(b != e)
            std::cout << ++count << "] " << *b++ << "\n";
    }
}

// Helper Functions
typename Forward_List<Editor::value_type>::iterator Editor::pos_iter(const unsigned line) {
    // Position Iterator
    unsigned count = 0;   
    typename Forward_List<value_type>::iterator b = list.begin(), e = list.end();
    while(b != e && ++count < line)
        ++b;

    return b;
}

typename Forward_List<Editor::value_type>::const_iterator Editor::pos_const_iter(const unsigned line) const {
    // Position Iterator
    unsigned count = 0;   
    typename Forward_List<value_type>::const_iterator b = list.cbegin(), e = list.cend();
    while(b != e && ++count < line)
        ++b;

    return b;
}

