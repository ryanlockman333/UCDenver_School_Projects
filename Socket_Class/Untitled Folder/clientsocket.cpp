/* 
 *clientsocket.cpp Class Implementations
*/

// Headers
#include <cstdlib>
#include <iostream>
#include <cstdio>
#include "clientsocket.h"

// Constructors
ClientSocket::ClientSocket(const char* const host, const int port) {
    if(!Socket::create()) {
        std::cerr << "create: error\n";
        throw -1;
    }
    
    if(!Socket::connect(host, port)) {
        std::cerr << "connect: error\n";
        throw -1;
    }
}

// Overloaded Operators
const ClientSocket& ClientSocket::operator<<(const std::string &str) const {
    if(!Socket::send(str)) {
        std::cerr << "send: error\n";
        throw -1;
    }

    return *this;
}

const ClientSocket& ClientSocket::operator>>(std::string &str) const {
    if(!Socket::recv(str)) {
        std::cerr << "recv: error\n";
        throw -1;
    }

    return *this;
}

