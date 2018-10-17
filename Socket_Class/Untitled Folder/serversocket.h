/* 
 *serversocket.h Class Prototypes
*/

#ifndef SERVERSOCKET_H
#define SERVERSOCKET_H

// Headers
#include <string>
#include "socket.h"

class ServerSocket : private Socket {
public:
    // Constructors
    ServerSocket() {}; // default, used only for accept(connfd) sockets
    ServerSocket(const char* const port);

    // Overloaded Operators
    const ServerSocket& operator<<(const std::string &str) const; // send
    const ServerSocket& operator>>(std::string &str) const;       // receive

    // Member Functions
    bool accept(ServerSocket &conn_sock);
};

#endif

