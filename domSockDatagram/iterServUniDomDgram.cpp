// Headers
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cerrno>
#include <cctype>
#include <string>
#include <unistd.h>
#include <sys/un.h>
#include <sys/socket.h>

// Constants
const char *const SOCK_PATH = "/tmp/unixDomDgram";
const size_t      BUF_SIZE  = 10;
const unsigned    BACKLOG   = 5;

// Main
int main() {
    // Declarations
    struct sockaddr_un svaddr, claddr;
    int sfd = 0;
    ssize_t nbytes = 0;
    char buf[BUF_SIZE];

    // Socket
    if((sfd = socket(AF_UNIX, SOCK_DGRAM, 0)) == -1) {
        std::perror("socket");
        return EXIT_FAILURE;
    }

    // Remove if Existing Path
    if(remove(SOCK_PATH) == -1 && errno != ENOENT) { // calls unlink and rmdir
        std::perror("remove");
        return EXIT_FAILURE;
    }

    // Zero Out
    std::memset(&svaddr, 0, sizeof(struct sockaddr_un));
    
    // Set Address Structure
    svaddr.sun_family = AF_UNIX;
    std::strncpy(svaddr.sun_path, SOCK_PATH, sizeof(svaddr.sun_path)-1);

    // Bind
    if(bind(sfd, (struct sockaddr*)&svaddr, sizeof(struct sockaddr_un)) == -1) {
        std::perror("bind");
        return EXIT_FAILURE;
    }

    // Loop Server
    for(;;) {
        socklen_t len = sizeof(struct sockaddr_un);
        
        if((nbytes = recvfrom(sfd, buf, BUF_SIZE, 0, (struct sockaddr*)&claddr, &len)) == -1) {
            std::perror("recvfrom");
            return EXIT_FAILURE;
        }

        std::cout << "\nServer Side Received: " << nbytes << " bytes from " << claddr.sun_path << '\n';

        for(ssize_t i = 0; i < nbytes; ++i)
            buf[i] = std::toupper((unsigned char)buf[i]);

        if(sendto(sfd, buf, nbytes, 0, (struct sockaddr*)&claddr, len) != nbytes) {
            std::perror("sendto");
            return EXIT_FAILURE;
        }
    }

    return 0; // shouldn't get here
}

