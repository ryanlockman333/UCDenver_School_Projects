// Headers
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Constants
static const unsigned BUF_SIZE = 256;

// Client Main
int main(int argc, char *argv[]) {
    // Check Args
    if(argc < 4 || !std::strcmp(argv[1], "-h")) {
        std::cerr << "\nUsage: " << argv[0] << " [host] [port] [msg...]\n\n";
        return EXIT_FAILURE;
    }

    // Typedefs
    typedef struct sockaddr sockaddr;
    typedef struct sockaddr_in6 sockaddr_in6;

    // Create Socket
    int sfd = socket(AF_INET6, SOCK_DGRAM, 0);
    if(sfd == -1) {
        std::perror("socket");
        return EXIT_FAILURE;
    }

    // Set Up Socket Address
    sockaddr_in6 svaddr;   
    memset(&svaddr, 0, sizeof(sockaddr_in6));
    svaddr.sin6_family = AF_INET6;
    svaddr.sin6_port   = htons(std::atoi(argv[2]));

    // Get Network Address of Server
    if(inet_pton(AF_INET6, argv[1], &svaddr.sin6_addr) <= 0) {
        std::perror("inet_pton");
        return EXIT_FAILURE;
    }

    // Loop in Cmd-Ln Msg
    for(int i = 3; i < argc; ++i) {
        std::size_t msgLen = std::strlen(argv[i]); // msg len
        
        // Send Msg to Server
        if(sendto(sfd, argv[i], msgLen, 0, (sockaddr*)&svaddr, sizeof(sockaddr_in6)) != (ssize_t)msgLen) {
            std::perror("sendto");
            return EXIT_FAILURE;
        }

        // Recieve Response from Server
        char resp[BUF_SIZE];
        ssize_t numBytes = recvfrom(sfd, resp, BUF_SIZE, 0, NULL, NULL);
        if(numBytes == -1) {
            std::perror("recvfrom");
            return EXIT_FAILURE;
        }

        // Print Response
        printf("Response %d: %.*s\n", i - 1, (int)numBytes, resp);
    }

    return EXIT_SUCCESS;
}

