/* 
 *clientsocket.cpp Class Implementations
*/

// Headers
#include <cstdlib>
#include <cstdio>  
#include "clientsocket.h"

// Constructors
ClientSocket::ClientSocket(const std::string host, const int port) {
    if(!Socket::create()) {
        perror("\nClient: create");
        throw -1;
    }
    
    if(!Socket::connect(host, port)) {
        perror("\nClient: connect");
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

// Member Functions
bool ClientSocket::makeClient(const std::string host, const int port) {
    if(!Socket::create()) {
        perror("\nClient: create");
        return false;
    }
    
    if(!Socket::connect(host, port)) {
        perror("\nClient: connect");
        return false;;
    }

    return true;
}
