/********************************************************************************************* 
 * Ryan Lockman                                                                              *
 * pa4functions.cpp                                                                          *
 * Description: pa4functions implementations.                                                *
 * 3/28/14                                                                                   *
 *********************************************************************************************/

// Headers
#include <limits>
#include <iostream>
#include "forward_list.h"
#include "pa4functions.h"

// Function Implementations
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
			return true;
}

void line_remove(Editor &editor) {
    unsigned line = 0;

    std::cout << "\nEnter line number: ";
    if(std::cin >> line) // validate
        editor.out_after_line(line);
    else
        flush_stream();
}

void nline_remove(Editor &editor) {
    unsigned line = 0;
    int n = 0;

    std::cout << "\nEnter line number: ";
    if(std::cin >> line) {
        std::cout << "\nHow many lines to remove: ";
        if(std::cin >> n) {
            if(n < 0)
                return;
            editor.nout_after_line(line, n);
        }
        else
            flush_stream();
    }
    else
        flush_stream();
}

void insert(Editor &editor) {
    std::string str;
    unsigned line = 0;

    std::cout << "\nEnter line number: ";
    if(std::cin >> line) {
        flush_stream();
        std::cout << "\nEnter line to insert after: ";
        if(std::getline(std::cin, str, '\n'))
            editor.in_after_line(line, str);
    }
    else
        flush_stream();
}

void ninsert(Editor &editor) {
    Forward_List<std::string> buf;
    std::string str;
    unsigned line = 0;
    int n = 0;

    std::cout << "\nEnter line number: ";
    if(std::cin >> line) {
        std::cout << "\nHow many lines to insert: ";
        if(std::cin >> n) {
            if(n < 0)
                return;

            flush_stream();
            
            // Loop Input Lines
            for(int i = 0; i < n; ++i) {
                std::cout << "\nType line " << i+1 << ": ";
                if(std::getline(std::cin, str, '\n'))
                    buf.push_front(str);
            }
            
            editor.nin_after_line(line, buf);
        }
        else
            flush_stream();
    }
    else
        flush_stream();
}

void fremove(Editor &editor) {
    std::string str;

    // Input
    std::cout << "\nEnter word to remove: ";
    std::cin  >> str;
    editor.remove_first(str);
}

void aremove(Editor &editor) {
    std::string str;

    // Input
    std::cout << "\nEnter word to remove: ";
    std::cin  >> str;
    editor.remove_all(str);
}

void freplace(Editor &editor) {
    std::string str, replace;

    // Input
    std::cout << "\nEnter word to replace: ";
    std::cin  >> str;
    std::cout << "\nEnter word to replace with: ";
    std::cin  >> replace;
    editor.replace_first(str, replace);
}

void areplace(Editor &editor) {
    std::string str, replace;

    // Input
    std::cout << "\nEnter word to replace: ";
    std::cin  >> str;
    std::cout << "\nEnter word to replace with: ";
    std::cin  >> replace;
    editor.replace_all(str, replace);
}

void flush_stream() {
    std::cin.clear(); // reset flags
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard stream input
}

