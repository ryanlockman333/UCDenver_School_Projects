/*
socket.tem class implementations
*/

// Headers
#include <fcntl.h>
#include <iostream>
#include "socket.h"

// Constructors
Socket::~Socket() {
    if(is_valid())
        ::close(sfd);
}

// All Init
bool Socket::create() {
    // Set Socket
    sfd = socket(AF_INET, SOCK_STREAM , 0);

    // Check Validity
    if(!is_valid())
        return false;

    // Time Wait
    int optval = 1;
    if(setsockopt(sfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof optval))
        return false;

    return true;
}

// Server Init
bool Socket::bind(const int port) {
    // Check Validity
    if(!is_valid())
        return false;

    // Set Up Address Family
    addr.sin_family      = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port        = htons(port);

    // Bind To Port
    if(::bind(sfd, (struct sockaddr*)&addr, sizeof addr))
        return false;

    return true;
}

bool Socket::listen() const {
    // Check Validity
    if(!is_valid())
        return false;

    // Set Up Listener
    if(::listen(sfd, BACKLOG))
        return false;

    return true;
}

bool Socket::accept(Socket &conn_sock) const {
    socklen_t slen = sizeof(addr);
    conn_sock.sfd = ::accept(sfd, (sockaddr*)&addr, &slen);
    if(conn_sock.sfd == -1)
        return false;

    return true;
}

// Client Init
bool Socket::connect(const std::string host, const int port) {
    // Check Validity
    if(!is_valid())
        return false;

    // Set Up Address Family
    addr.sin_family = AF_INET;
    addr.sin_port   = htons(port);

    // Convert IP From Text To Binary
    if(inet_pton(AF_INET, host.c_str(), &addr.sin_addr) == -1)
        return false;

    // Connect
    if(::connect(sfd, (sockaddr*)&addr, sizeof addr))
        return false;

    return true;
}

// Data Trans
int Socket::send(const std::string str) const {
    // Send Packet
    ssize_t ret = ::send(sfd, str.c_str(), str.size(), MSG_NOSIGNAL);
    if(ret == -1)
        return -1;
    else if(!ret)
        return 0;

    return (int)ret;
}

int Socket::recv(std::string &str) const {
    char buf[MAXRECV+1];

    // Zero Out Buffer
    std::memset(buf, 0, MAXRECV+1);

    // Receive Packet
    int ret = ::recv(sfd, buf, MAXRECV, 0);
    if(ret == -1)
        return -1;
    else if(!ret)
        return 0;

    // Read Bytes
    str = buf;
    return (int)ret;
}

// Other Member Funtions
bool Socket::set_non_blocking(const bool set_flag) {
    // Get Flag Mask
    int flags = fcntl(sfd, F_GETFL);
    if(flags == -1)
        return false;

    // OR(Set) or AND(Unset) Block Flag in Mask
    if(set_flag)
        flags |=  O_NONBLOCK;
    else
        flags &= ~O_NONBLOCK;

    // Set Flag Mask
    if(fcntl(sfd, F_SETFL, flags) == -1)
        return false;

    return true;
}

