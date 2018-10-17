#define _XOPEN_SOURCE 600

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <unistd.h>
#include <signal.h>

// Global Statics
static char *str2 = NULL;
static int handled = 0;

// Signal Handler
static void handler(int sig) { // uses crypt, non-rentrant and non-async-signal-safe
    crypt(str2, "xx");
    ++handled;
}

// Main
int main(int argc, char *argv[]) {
    // Check Args
    if(argc != 3) {
        std::cerr << "\nUsage: " << argv[0] << " [str1] [str2]\n\n";
        return EXIT_FAILURE;
    }

    // Assign Arg
    str2 = argv[2];
    
    // Duplicate argv[1] String
    char *cr1 = strdup(crypt(argv[1], "xx")); // strdup hides malloc and is non-overflow-safe, non-rentrant, and leaks memory
    if(!cr1) {
        std::perror("\ncrypt");
        return EXIT_FAILURE;
    }

    // Initialize Struct
    struct sigaction sa;
    sigemptyset(&sa.sa_mask); // empty it
    sa.sa_flags = 0;
    sa.sa_handler = handler;

    // Set Mask for SIGINT
    if(sigaction(SIGINT, &sa, NULL) == -1) {
        std::cerr << "\nsigaction error\n";
        return EXIT_FAILURE;
    }

    /* Repeatedly call crypt() using argv[1]. If interrupted by a
    signal handler, then the static storage returned by crypt()
    will be overwritten by the results of encrypting argv[2], and
    strcmp() will detect a mismatch with the value in 'cr1'. */
    for(int callNum = 1, mismatch = 0; ; ++callNum)
        if(std::strcmp(crypt(argv[1], "xx"), cr1) != 0) {
            ++mismatch;
            std::cout << "\nMissmatch on call " << callNum
                      << " (mismatch = " << mismatch << " handled = " << handled << ")\n";
        }
}

