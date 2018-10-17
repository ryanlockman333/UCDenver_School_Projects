/*
socket.tem class implementations
*/

// Headers
#include <cerrno>
#include <fcntl.h> 
#include "socket.h"

// Constructors
Socket::~Socket() {
    if(is_valid())
        ::close(m_sock);
}

// Server Init
bool Socket::create() {
    // Set Socket
    m_sock = socket(AF_INET, SOCK_STREAM, 0);

    // Check Validity
    if(!is_valid())
        return false;

    // Time Wait
    int on = 1;
    if(setsockopt(m_sock, SOL_SOCKET, SO_REUSEADDR, (const char*)&on, sizeof on) == -1)
        return false;

    return true;
}

bool Socket::bind(const int port) {
    // Check Validity
    if(!is_valid())
        return false;

    // Set Up Address Family
    m_addr.sin_family      = AF_INET;
    m_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    m_addr.sin_port        = htons(port);

    // Bind To Port
    int bind_return = ::bind(m_sock, (struct sockaddr*)&m_addr, sizeof m_addr);
    if(bind_return == -1)
        return false;

    return true;
}

bool Socket::listen() const {
    // Check Validity
    if(!is_valid())
        return false;

    // Set Up Listener
    int listen_return = ::listen(m_sock, BACKLOG);
    if(listen_return == -1)
        return false;

    return true;
}

bool Socket::accept(Socket &new_socket) const {
    int addr_length   = sizeof m_addr;
    new_socket.m_sock = ::accept(m_sock, (sockaddr*)&m_addr, (socklen_t*)&addr_length);

    if(new_socket.m_sock <= 0)
        return false;
    else
        return true;
}

// Client Init
bool Socket::connect(const std::string host, const int port) {
    // Check Validity
    if(!is_valid())
        return false;

    // Set Up Address Family
    m_addr.sin_family = AF_INET;
    m_addr.sin_port   = htons(port);

    // Convert IP From Text To Binary
    int status = inet_pton(AF_INET, host.c_str(), &m_addr.sin_addr);
    if(errno == EAFNOSUPPORT)
        return false;

    // Connect
    status = ::connect(m_sock, (sockaddr*)&m_addr, sizeof m_addr);

    if(status == 0)
        return true;
    else
        return false;
}

// Data Trans
bool Socket::send(const std::string str) const {
    // Send Packet
    int status = ::send(m_sock, str.c_str(), str.size(), MSG_NOSIGNAL);
    
    if(status == -1)
        return false;
    else
        return true;
}

int Socket::recv(std::string &str) const {
    char buf[MAXRECV+1];

    // Zero Out Buffer
    memset(buf, 0, MAXRECV+1);

    // Check Status
    int status = ::recv(m_sock, buf, MAXRECV, 0);
    if(status == -1) {
        std::cout << "status == -1   errno == " << errno << "  in Socket::recv\n";
        return 0;
    }
    else if(status == 0)
        return 0;
    else {
        str = buf;
        return status;
    }
}

int Socket::getConn() const {
    char buf[MAXRECV];
    std::cout << "\nGot connection from IP:   " << inet_ntop(AF_INET, &m_addr.sin_addr, buf, sizeof buf)
              << "                      Port: " << ntohs(m_addr.sin_port);
}

// Other Member Funtions
void Socket::set_non_blocking(const bool b) {
    int opts = 0;

    opts = fcntl(m_sock, F_GETFL);

    if(opts < 0)
        return;

    if(b)
        opts = ( opts | O_NONBLOCK );
    else
        opts = ( opts & ~O_NONBLOCK );

    fcntl(m_sock, F_SETFL, opts);
}

