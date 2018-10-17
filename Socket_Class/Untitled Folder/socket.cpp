/*
socket.tem class implementations
*/

// Headers
#include <iostream>
#include <cstdio>
#include <cerrno>
#include <fcntl.h>
#include "socket.h"

// Constructors
Socket::Socket() : sfd(-1), addr(), sa_addr() {
    std::memset(&addr, 0, sizeof addr);
    std::memset(&sa_addr, 0, sizeof sa_addr);
} 

Socket::~Socket() { if(is_valid()) ::close(sfd); }

// All Init
bool Socket::create() {
    // Set Socket
    if((sfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        std::perror("socket");
        return false;
    }

    // Set Socket Options
    int optval = 1;
    if(setsockopt(sfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof optval)) {
        std::perror("setsockopt");
        return false;
    }

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
    if(::bind(sfd, (sockaddr*)&addr, sizeof addr)) {
        std::perror("bind");
        return false;
    }

    return true;
}

bool Socket::listen() const {
    // Check Validity
    if(!is_valid())
        return false;

    // Set Up Listener
    if(::listen(sfd, BACKLOG)) {
        std::perror("listen");
        return false;
    }

    return true;
}

bool Socket::accept(Socket &conn_sock) {
    // Constants
    const unsigned ADDRSTRLEN = (NI_MAXHOST+NI_MAXSERV+10);

    // Declarations
    socklen_t addrlen = sizeof(sockaddr_storage);
    char host[NI_MAXHOST], service[NI_MAXSERV], addrStr[ADDRSTRLEN];

    // Accept Incomming Connection Socket
    if((conn_sock.sfd = ::accept(sfd, (sockaddr*)&conn_sock.sa_addr, &addrlen)) == -1) {
        std::perror("accept");
        return false;
    }

    // Get Name Info of Client
    if(getnameinfo((sockaddr*)&conn_sock.sa_addr, addrlen, host, NI_MAXHOST, service, NI_MAXSERV, 0)) {
        std::perror("getnameinfo");
        std::snprintf(addrStr, ADDRSTRLEN, "(UNKNOWN)");
    }
    else
        std::snprintf(addrStr, ADDRSTRLEN, "(%s, %s)", host, service);      

    std::cout << "\nGot Connection From: " << addrStr;
    return true;
}

bool Socket::makeServer(const char* const port) {
    // Set Up Hints Struct for getaddrinfo
    addrinfo hints;   
    std::memset(&hints, 0, sizeof(addrinfo));
    hints.ai_protocol  = 0;                           // wild proto
    hints.ai_canonname = NULL;
    hints.ai_addr      = NULL;
    hints.ai_next      = NULL;
    hints.ai_socktype  = SOCK_STREAM;                 // stream
    hints.ai_family    = AF_UNSPEC;                   // ip4 and ip6
    hints.ai_flags     = AI_PASSIVE | AI_NUMERICSERV; // wild ip and numeric service name

    // Resolve Addr Structs List
    addrinfo *result = NULL;
    if(getaddrinfo(NULL, port, &hints, &result)) {    // resolve through listen sock
        std::perror("getaddrinfo");
        return false;
    }

    // Loop Through Addr Structs for Bindable Addr
    addrinfo *rp = result;
    int optval = 1;
    for(; rp; rp = rp->ai_next) {
        // Create Socket
        if((sfd = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol)) == -1)
            std::perror("socket");
        
        // Set Socket Options
        if(setsockopt(sfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval))) {
            std::perror("setsockopt");
            return false;
        }
       
        // Bind Socket
        if(::bind(sfd, rp->ai_addr, rp->ai_addrlen)) {
            std::perror("bind");
            if(close(sfd))
                std::perror("close");
        }

        break; // success
    }

    // Check Unsuccessful Bind
    if(!rp) {
        std::cerr << "\nCould not bind address to socket\n";
        return false;
    }

    // Deallocate Addr Structs List
    freeaddrinfo(result);

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
    if(inet_pton(AF_INET, host.c_str(), &addr.sin_addr) == -1) {
        std::perror("inet_pton");
        return false;
    }

    // Connect
    if(::connect(sfd, (sockaddr*)&addr, sizeof addr)) {
        std::perror("connect");
        return false;
    }

    return true;
}

bool Socket::makeClient(const char* const host, const char* const port) {
    // Set Up Hints Struct for getaddrinfo
    addrinfo hints;
    std::memset(&hints, 0, sizeof(addrinfo));
    hints.ai_protocol  = 0;              // wild proto   
    hints.ai_canonname = NULL;
    hints.ai_addr      = NULL;
    hints.ai_next      = NULL;
    hints.ai_socktype  = SOCK_STREAM;
    hints.ai_family    = AF_UNSPEC;      // ip4 and ip6   
    hints.ai_flags     = AI_NUMERICSERV; // numeric service name

    // Get Addr Structs List
    addrinfo *result = NULL;
    if(getaddrinfo(host, port, &hints, &result)) {
        std::perror("getaddrinfo");
        return false;
    }

    // Loop Through Addr Structs for Connectable Addr
    addrinfo *rp = result;
    for(; rp; rp = rp->ai_next) {
        // Create Socket
        if((sfd = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol)) == -1)
            std::perror("socket");

        // Connect Socket
        if(::connect(sfd, rp->ai_addr, rp->ai_addrlen)) {
            std::perror("connect");
            if(close(sfd))
                std::perror("close");
        }
        
        std::cout << "Connect: connection established";
        break; // success
       }

    // Check Unsuccessful Connect
    if(!rp) {
        std::cerr << "\nCould not connect address to socket\n";
        return false;
    }

    // Deallocate Addr Structs List
    freeaddrinfo(result);

    return true;
}

// Data Trans
int Socket::send(const std::string str) const {
    // Send Packet
    ssize_t ret = ::send(sfd, str.c_str(), str.size(), MSG_NOSIGNAL);
    if(ret == -1) {
        std::perror("send");
        return -1;
    }
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
    if(ret == -1) {
        std::perror("recv");
        return -1;
    }
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
    if(flags == -1) {
        std::perror("fcntl - F_GETFL");
        return false;
    }

    // OR(Set) or AND(Unset) Block Flag in Mask
    if(set_flag) flags |=  O_NONBLOCK;
    else         flags &= ~O_NONBLOCK;

    // Set Flag Mask
    if(fcntl(sfd, F_SETFL, flags) == -1) {
        std::perror("fcntl - F_SETFL");
        return false;
    }

    return true;
}

ssize_t read_line(int fd, void *buffer, const std::size_t n) { // Read Marshalled Data+Codebase
     // Check Params    
     if(n <= 0 || !buffer) {
         errno = EINVAL;
         return -1;
     }
 
     // Declarations
     ssize_t numRead = 0;
     std::size_t totRead = 0;
     char ch = 0;
     char *buf = (char*)buffer;   // no ptr arithmetic on void*
 
     // Loop Read
     for(;;) {
         if((numRead = read(fd, &ch, 1)) == -1 && errno != EINTR) { // contiunue on iterupt
             std::perror("read");
             return -1;
         }
 
         // Check Read Return
         if(!numRead) {
             if(!totRead) // total bytes read(0)
                 return 0;

            break;        // EOF(0)
         }
 
         // Discard if > n-1 Bytes
         if(totRead < n-1) {
             *buf++ = ch;
             ++totRead;
         }
 
         // Break on Newln
         if(ch == '\n')
             break;
     }
 
     // NULL Terminate
     *buf = '\0';
     return totRead;
}

