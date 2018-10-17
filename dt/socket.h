/*
socket.h class prototypes
*/

#ifndef SOCKET_H
#define SOCKET_H

// Headers
#include <iostream>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <string>
#include <arpa/inet.h>

// Global Constants
const int MAXHOSTNAME = 200, BACKLOG = 1024, MAXRECV = 4096;
//const int MSG_NOSIGNAL = 0; // defined by dgame

class Socket {
public:
    // Constructors
    Socket() : m_sock(-1) { memset(&m_addr, 0, sizeof m_addr); } // default
    virtual ~Socket(); // destructor

    // Server Init
    bool create();
    bool bind(const int port);
    bool listen() const;
    bool accept(Socket &s) const;

    // Client Init
    bool connect(const std::string host, const int port);

    // Data Trans
    bool send(const std::string str) const;
    int  recv(std::string &str) const;

    // Constant Member Functions
    bool is_valid() const { return m_sock != -1; }  
    int printConn() const;

    // Other Member Functions
    void set_non_blocking (const bool b);

private:
    // Data Members
    int m_sock;
    sockaddr_in m_addr;
};

#endif

