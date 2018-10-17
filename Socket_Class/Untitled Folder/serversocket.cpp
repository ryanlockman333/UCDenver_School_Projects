/*
 *serversocket.cpp Class Implementations
*/

// Headers
#include <cstdlib>
#include <iostream>
#include <cstdio>
#include "serversocket.h"

// Constructors
ServerSocket::ServerSocket(const char* const port) {
    // Make Server Socket
    if(!Socket::makeServer(port)) {
        std::cerr << "makeServer: error\n";
        throw -1;
    }

    // Turn into Listen Socket
    if(!Socket::listen()) {
        std::cerr << "listen: error\n";
        throw -1;
    }
}
              
// Overloaded Operators             
const ServerSocket& ServerSocket::operator<<(const std::string &str) const {
    if(!Socket::send(str)) {
        std::cerr << "send: error\n";
        throw -1;
    }

    return *this;
}

const ServerSocket& ServerSocket::operator>>(std::string &str) const {
    if(!Socket::recv(str)) {
        std::cerr << "recv: error\n";
        throw -1;
    }

    return *this;
}

// Member Functions
bool ServerSocket::accept(ServerSocket &conn_sock) {
    if(!Socket::accept(conn_sock)) {
        std::cerr << "accept: error\n";
        return false;
    }

    return true;
}

