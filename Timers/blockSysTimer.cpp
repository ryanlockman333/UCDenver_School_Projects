// Headers
#include <iostream>
#include <cstring>
#include <csignal>
#include <cstdlib>
#include <cstdio>
#include <cerrno>
#include <unistd.h>

// Defines
#define BUF_SIZE 200 // Unsafe

// Functions
static void handler(int sig) { printf("Caught signal\n"); } // Unsafe

// Main
int main(int argc, char **argv) {
// Declarations
    char buf[BUF_SIZE];

// Check Args
    if((argc > 1 && !std::strcmp(argv[1], "-h")) || argc > 3) {
        std::cerr << "\nUsage:  " << argv[0] << " [num-secs] [restart-flag]\n\n";
        return EXIT_FAILURE;
    }

// Set Up Signal Handler
    struct sigaction sa;
    sa.sa_flags = (argc > 2) ? SA_RESTART : 0;
    sigemptyset(&sa.sa_mask);
    sa.sa_handler = handler;

    if(sigaction(SIGALRM, &sa, NULL)) {
        std::perror("sigaction");
        return EXIT_FAILURE;
    }

// Set Up Alarm for Blocked Read
    alarm((argc > 1) ? std::atoi(argv[1]) : 10);
    
// Read(Blocks)
    ssize_t numRead = read(STDIN_FILENO, buf, BUF_SIZE - 1); /* could produce race conditions
                                                                from alarm to here(second or so)
                                                                during block */
    
    // Save Errno
    int savedErrno = errno;
    alarm(0); // disable alarm incase read returned before timer
    errno = savedErrno;

    // Check Error
    if(numRead == -1) {
        if(errno == EINTR) // interuppted
            printf("Read timed out\n");
        else
            std::perror("read");
    }
    else
        printf("Successful read (%ld bytes): %.*s", (long)numRead, (int)numRead, buf);

// End
    return EXIT_SUCCESS;
}

