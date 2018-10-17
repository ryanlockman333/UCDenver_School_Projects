/*
socket.h class prototypes
*/

// Macros
#ifndef SOCKET_H
#define SOCKET_H

// Feature Test Macros
#ifndef _BSD_SOURCE
#define _BSD_SOURCE // NI_MAXHOST, NI_MAXSERV from <netdb.h>
#endif

// Headers
#include <string>
#include <cstring>
#include <vector>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

// Global Constants
const int MAXHOST = NI_MAXHOST, MAXSERV = MAXSERV, BACKLOG = 1024, MAXRECV = 4096;
//const int MSG_NOSIGNAL = 0;                                        // defined by dgame

// Socket Class
class Socket {
public:
    // Constructors
    Socket();          // default
    virtual ~Socket(); // destructor

    // All Init
    bool create();                                                   // ip dependant(ip4, calls ::socket, ::setsockopt)

    // Server Init
    bool bind(const int port);                                       // ip dependant(ip4)
    bool listen() const;
    bool accept(Socket &s);
    bool makeServer(const char* const port);                         // non-ip dependant(calls ::socket, ::bind, ::setsockopt)

    // Client Init
    bool connect(const std::string host, const int port);            // ip dependant(ip4)
    bool makeClient(const char* const host, const char* const port); // non-ip dependant(calls ::socket, ::connect)

    // Data Trans
    int send(const std::string str) const;
    int recv(std::string &str) const;
    ssize_t read_line(int fd, void *buffer, const std::size_t n); // marshalling

    // Member Functions
    bool is_valid() const { return sfd != -1; }
    bool set_non_blocking(const bool);

private:
    // Data Members
    int sfd;
    sockaddr_in addr; // ip4 only
    sockaddr_storage sa_addr;
};

#endif

