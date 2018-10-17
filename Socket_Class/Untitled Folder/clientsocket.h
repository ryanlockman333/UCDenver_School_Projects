/*
 *clientsocket.h Class Prototypes
*/

#ifndef CLIENTSOCKET_H
#define CLIENTSOCKET_H

// Headers
#include <string>
#include "socket.h"

class ClientSocket : private Socket {
public:
    // Constructors
    ClientSocket(const char* const host, int port); // defaut

    // Overloaded Operators
    const ClientSocket& operator<<(const std::string &str) const; // send
    const ClientSocket& operator>>(std::string &str)  const;      // receive
};

#endif

