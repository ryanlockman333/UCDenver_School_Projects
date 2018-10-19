/*
socket.tem class implementations
*/

// Headers
#include <cstring>
#include <string>
#include <cerrno>
#include <cstdio>
#include <fcntl.h> 
#include "socket.h"

// Constructors
Socket::Socket() : sockfd(-1) { 
    memset(&m_addr, 0, sizeof m_addr); 
    //bzero((char *)&m_addr, sizeof m_addr);
}

Socket::~Socket() { if(is_valid()) ::close(sockfd); }

// Server Init
bool Socket::create() {
    // Create Server Socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(!is_valid())
        return false;

    // Lose Address in Use Error for Port Bind
    int yes = 1;
    if(setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1)
        return false;

    return true;
}

bool Socket::bind(const int port) {
    if(!is_valid())
        return false;

    // Set Host Address Structure
    m_addr.sin_family      = AF_INET;
    m_addr.sin_addr.s_addr = INADDR_ANY;
    m_addr.sin_port        = htons(port);

    // Bind Port
    if(::bind(sockfd, (struct sockaddr*)&m_addr, sizeof m_addr) < 0)
        return false;

    return true;
}

bool Socket::listen() const {
    if(!is_valid())
        return false;

    // Listen
    if(::listen(sockfd, BACKLOG) < 0)
        return false;

    return true;
}

bool Socket::accept(Socket &new_sock) const {
    // Wait for CLient Acception
    int cli_addr = sizeof m_addr;
    new_sock.sockfd = ::accept(sockfd, (sockaddr*)&m_addr, (socklen_t*)&cli_addr);
    if(new_sock.sockfd < 0)
        return false;
        
    std::cout << "\nGot connection from: " << inet_ntoa(m_addr.sin_addr) 
              << "\nPort: " << ntohs(m_addr.sin_port) << "\n";
    return true;
}

// Client Init
bool Socket::connect(const std::string host, const int port) {
    if(!is_valid())
        return false;

    // Set Client Address Structure
    m_addr.sin_family = AF_INET;
    m_addr.sin_port   = htons(port);

    // Convert IPv4/IpV6 from Text to Binary
    inet_pton(AF_INET, host.c_str(), &m_addr.sin_addr);
    if(errno == EAFNOSUPPORT)
        return false;

    // Connect to Server Socket
    if(::connect(sockfd, (sockaddr*)&m_addr, sizeof m_addr) < 0);
        return false;
   
    return true;
}

// Data Trans
bool Socket::send(const std::string str) const {
    if(::send(sockfd, str.c_str(), str.size(), MSG_NOSIGNAL) < 0) // send packet
        return false;
    else
        return true;
}

int Socket::recv(std::string &str) const {
    char buffer[MAXRECV+1];

    //bzero(buffer, MAXRECV+1); // zero out buffer
    memset(buffer, 0, MAXRECV+1); 

    // Receive Packet
    int status = ::recv(sockfd, buffer, MAXRECV, 0);
    if(status < 0) {
        perror("Socket::recv");
        return 0;
    }
    else if(status == 0)
        return 0;
    else {
        str = buffer;
        return status;
    }
}

// Other Member Funtions
void Socket::set_non_block(const bool setBlock) {
    int opts = fcntl(sockfd, F_GETFL);
    if(opts < 0)
        return;

    if(setBlock)
        opts = (opts | O_NONBLOCK);
    else
        opts = (opts & ~O_NONBLOCK);

    fcntl(sockfd, F_SETFL, opts);
}

