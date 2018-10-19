/*
sockexcp.h Class prototypes/implementations
*/

#ifndef SOCKEXCP_H
#define SOCKEXCP_H

// Headers
#include <string>

class SockExcp {
public:
    // Constructors
    SockExcp() : msg() {} // default
    SockExcp(const std::string str) : msg(str) {};

    // Other Member Functions
    std::string description() const { return msg; }

private:
    // Data Members
    std::string msg;
};

#endif

