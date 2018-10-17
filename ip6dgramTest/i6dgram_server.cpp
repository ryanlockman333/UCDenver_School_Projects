// Headers
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Constants
static const unsigned BUF_SIZE = 256;

// Server Main
int main(int argc, char **argv) {
    // Check Args
    if(argc < 2 || !std::strcmp(argv[1], "-h")) {
        std::cerr << "\nUsage: " << argv[0] << " [port]\n\n";
        return EXIT_FAILURE;
    }

    // Typedefs
    typedef struct sockaddr sockaddr;
    typedef struct sockaddr_in6 sockaddr_in6;

    // Declarations
    sockaddr_in6 servaddr, cliaddr;
    char buf[BUF_SIZE], cliaddrStr[INET6_ADDRSTRLEN];
    
    // Create Socket
    int sfd = socket(AF_INET6, SOCK_DGRAM, 0);
    if(sfd == -1) {
        std::perror("socket");
        return EXIT_FAILURE;
    }

    // Set Up Socket
    memset(&servaddr, 0, sizeof(sockaddr_in6));
    servaddr.sin6_family = AF_INET6;
    servaddr.sin6_addr   = in6addr_any; // wild
    servaddr.sin6_port   = htons(std::atoi(argv[1]));

    // Bind Socket
    if(bind(sfd, (sockaddr*)&servaddr, sizeof(sockaddr_in6))) {
        std::perror("bind");
        return EXIT_FAILURE;
    }

    // Loop Server
    for(;;) {
        socklen_t len  = sizeof(sockaddr_in6); // sock length

        // Receive From Client
        ssize_t nbytes = recvfrom(sfd, buf, BUF_SIZE, 0, (sockaddr*)&cliaddr, &len);
        if(nbytes == -1) {
            std::perror("recvfrom");
            return EXIT_FAILURE;
        }

        // Get/Print Client Address
        if(!inet_ntop(AF_INET6, &cliaddr.sin6_addr, cliaddrStr, INET6_ADDRSTRLEN))
            std::perror("inet_ntop");
        else
            std::cout << "\nServer Received: " << nbytes << " bytes from ("
                      << cliaddrStr << ", " << ntohs(cliaddr.sin6_port) << ")\n";

        // Uppercase Received
        for(int i = 0; i < nbytes; ++i)
            buf[i] = std::toupper((unsigned char)buf[i]);

        // Send Back Uppercase to Client
        if(sendto(sfd, buf, nbytes, 0, (sockaddr*)&cliaddr, len) != nbytes) {
            std::perror("sendto");
            return EXIT_FAILURE;
        }
    }

    // Shouldn't Get Here
    return EXIT_FAILURE;
}

