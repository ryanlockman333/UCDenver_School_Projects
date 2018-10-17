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
const char     *SOCK_PATH = "/tmp/myUniDomaSock";
const size_t    BUF_SIZE  = 256;
const unsigned  BACKLOG   = 5;

// Main
int main() {
    // Declarations
    struct sockaddr_un addr;
    int sfd = 0;
    ssize_t nread = 0;
    char buf[BUF_SIZE];

    // Socket
    if((sfd = socket(AF_UNIX, SOCK_STREAM, 0)) == -1) {
        std::perror("socket");
        return EXIT_FAILURE;
    }

    // Zero Out
    std::memset(&addr, 0, sizeof(struct sockaddr_un));

    // Set Up Address Structure
    addr.sun_family = AF_UNIX;
    std::strncpy(addr.sun_path, SOCK_PATH, sizeof(addr.sun_path)-1);

    // Connect
    if(connect(sfd, (struct sockaddr*)&addr, sizeof(struct sockaddr_un)) == -1) {
        std::perror("connect");
        return EXIT_FAILURE;
    }

    // Copy stdin to Socket
    ssize_t ret = 0;
    while((nread = read(STDIN_FILENO, buf, BUF_SIZE)) > 0)
        if((ret = write(sfd, buf, nread)) == -1) {
            std::perror("write");
            return EXIT_FAILURE;
        }
        else if(ret != nread) {
            std::cerr << "\npartial write";
            return EXIT_FAILURE;
        }

    // Chec Read Error
    if(nread == -1) {
        std::perror("read");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS; // server recieves EOF
}

