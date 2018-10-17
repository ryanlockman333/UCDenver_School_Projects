// Headers
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <unistd.h>
#include <sys/un.h>
#include <sys/socket.h>

// Constants
const char     *SOCK_PATH = "/tmp/unixDomDgram";
const size_t    BUF_SIZE  = 10;
const unsigned  BACKLOG   = 5;

// Main
int main(int argc, char *argv[]) {
    // Check Arguments
    if(argc < 2 || std::strcmp(argv[1], "-h") == 0) {
        std::cerr << "\n\nUsage: " << argv[0] << " [mag...]\n";
        return EXIT_FAILURE;
    }

    // Declarations
    struct sockaddr_un svaddr, claddr;
    int sfd = 0;
    std::size_t msgLen = 0;
    ssize_t nbytes = 0;
    char resp[BUF_SIZE];

    // Socket
    if((sfd = socket(AF_UNIX, SOCK_DGRAM, 0)) == -1) {
        std::perror("socket");
        return EXIT_FAILURE;
    }

    // Set Up Address Client Structure
    std::memset(&claddr, 0, sizeof(struct sockaddr_un));
    claddr.sun_family = AF_UNIX;
    std::snprintf(claddr.sun_path, sizeof(claddr.sun_path), "/tmp/unixDomDgram_cl.%ld", (long)getpid());

    // Bind
    if(bind(sfd, (struct sockaddr*)&claddr, sizeof(struct sockaddr_un)) == -1) {
        std::perror("connect");
        return EXIT_FAILURE;
    }

    // Set Up Address Server Structure
    std::memset(&svaddr, 0, sizeof(struct sockaddr_un));
    svaddr.sun_family = AF_UNIX;
    std::strncpy(svaddr.sun_path, SOCK_PATH, sizeof(svaddr.sun_path)-1);

    // Send Msg to Server
    for(int i = 1; i < argc; ++i) {
        msgLen = std::strlen(argv[i]); // may be longer than BUFF_SIZE
        if(sendto(sfd, argv[i], msgLen, 0, (struct sockaddr*)&svaddr, sizeof(struct sockaddr_un)) != (ssize_t)msgLen) {
            std::perror("sendto");
            return EXIT_FAILURE;
        }

        if((nbytes = recvfrom(sfd, resp, BUF_SIZE, 0, NULL, NULL)) == -1) {
            std::perror("recvfrom");
            return EXIT_FAILURE;
        }
        std::printf("\nClient Side Response %d: %.*s\n", i, (int)nbytes, resp);       
        //std::cout << "\nResponse: " << i << ": "
    }

    remove(claddr.sun_path);
    return EXIT_SUCCESS; // server recieves EOF
}

