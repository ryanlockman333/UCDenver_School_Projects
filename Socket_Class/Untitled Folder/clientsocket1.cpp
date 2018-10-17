/* 
 *clientsocket.cpp Class Implementations
*/

// Headers
#include <cstdlib>
#include <cstdio>  
#include "clientsocket.h"

// Constructors
ClientSocket::ClientSocket(const char* const host, const char* const port) {
    if(!Socket::makeClient(host, port)) {
        perror("\nClient: makeClient");
        throw -1;
    }
}

// Overloaded Operators
const ClientSocket& ClientSocket::operator<<(const std::string &str) const {
    if(!Socket::send(str)) {
        perror("\nClient: send");
        throw -1;
    }

    return *this;
}

const ClientSocket& ClientSocket::operator>>(std::string &str) const {
    if(!Socket::recv(str)) {
        std::perror("\nClient: recv");
        throw -1;
    }

    return *this;
}

