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
    ClientSocket(const std::string host, const int port); // defaut

    // Overloaded Operators
    const ClientSocket& operator<<(const std::string &str) const; // send
    const ClientSocket& operator>>(std::string &str)  const;      // receive

    // Member Functions
    bool makeClient(const std::string host, const int port);
};

#endif

