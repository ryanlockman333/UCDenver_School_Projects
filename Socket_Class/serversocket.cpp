/*
 *serversocket.cpp Class Implementations
*/

// Headers
#include <cstdlib>
#include <cstdio>  
#include "serversocket.h"

// Constructors
ServerSocket::ServerSocket(int port) {
    // Create Socket
    if(!Socket::create()) {
        std::perror("\nServer: create");
        throw -1;
    }

    // Bind Socket
    if(!Socket::bind(port)) {
        std::perror("\nServer: bind");
        throw -1;
    }
    
    // Make Listen Socket
    if(!Socket::listen()) {
        std::perror("\nServer: listen");
        throw -1;
    }
}
              
// Overloaded Operators             
const ServerSocket& ServerSocket::operator<<(const std::string &str) const {
    if(!Socket::send(str)) {
        std::perror("\nServer: send");
        throw -1;
    }

    return *this;
}

const ServerSocket& ServerSocket::operator>>(std::string &str) const {
    if(!Socket::recv(str)) {
        std::perror("\nServer: recv");
        throw -1;
    }

    return *this;
}

// Member Functions
bool ServerSocket::accept(ServerSocket &conn_sock) {
    if(!Socket::accept(conn_sock)) {
        perror("\nServer: accept error");
        return false;
    }

    return true;
}

