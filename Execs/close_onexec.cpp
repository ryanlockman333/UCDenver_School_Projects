#include <cstdlib>
#include <cstdio>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv) {
    // Check Args
    if(argc > 1) {
        // Get Flag Mask
        int flags = fcntl(STDOUT_FILENO, F_GETFD);
        if(flags == -1) {
            std::perror("fcntl - F_GETFD");
            return EXIT_FAILURE;
        }
        
        // OR In Bit
        flags |= FD_CLOEXEC;
        
        // Set Flag Mask
        if(fcntl(STDOUT_FILENO, F_SETFD, flags) == -1) {
            std::perror("fcntl - F_SETFD");
            return EXIT_FAILURE;
        }
    }

    // Execute
    execlp("ls", "ls", "-l", argv[0], (char*)NULL); // ls only this program(argv[0])
    std::perror("execlp");
    return EXIT_FAILURE;
}

