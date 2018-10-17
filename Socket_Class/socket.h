/*
socket.h class prototypes
*/

#ifndef SOCKET_H
#define SOCKET_H

// Feature Test Macros
#ifndef _BSD_SOURCE
    #define _BSD_SOURCE // NI_MAXHOST, NI_MAXSERV from <netdb.h>
#endif

// Headers
#include <string>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

// Global Constants
const int MAXHOST = NI_MAXHOST, MAXSERV = MAXSERV, BACKLOG = 1024, MAXRECV = 4096;
//const int MSG_NOSIGNAL = 0; // defined by dgame

class Socket {
public:
    // Constructors
    Socket() : sfd(-1) { std::memset(&addr, 0, sizeof addr); } // default
    virtual ~Socket();                                         // destructor

    // All Init
    bool create();   

    // Server Init
    bool bind(const int port);
    bool listen() const;
    bool accept(Socket &s) const;

    // Client Init
    bool connect(const std::string host, const int port);

    // Data Trans
    int send(const std::string str) const;
    int recv(std::string &str) const;

    // Member Functions
    bool is_valid() const { return sfd != -1; }
    bool set_non_blocking(const bool b);

private:
    // Data Members
    int sfd;
    sockaddr_in addr;
};

#endif

