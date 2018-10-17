// Feature Test Macros
#define _POSIX_C_SOURCE 199309

// Headers
#include <iostream>
#include <cstring>
#include <ctime>
#include <csignal>
#include <cstdlib>
#include <cstdio>
#include <cerrno>
#include <sys/time.h>

// Functions
static void sigintHandler(int sig) {}

// Main
int main(int argc, char **argv) {
// Check Args
    if(argc != 3 || !std::strcmp(argv[1], "-h")) {
        std::cerr << '\n' << argv[0] << " [secs] [nanosecs]\n\n";
        return EXIT_FAILURE;
    }

// Declarations
    timeval  start, finish;
    timespec request, remain;

// Set Requested Timespec
    request.tv_sec  = std::atol(argv[1]);
    request.tv_nsec = std::atol(argv[2]);

// Set Up Signal Handler
    struct sigaction sa;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sa.sa_handler = sigintHandler;

    if(sigaction(SIGINT, &sa, NULL)) {
        std::perror("sigaction");
        return EXIT_FAILURE;
    }

// Get Start Time
    if(gettimeofday(&start, NULL)) {
        std::perror("gettimeofday");
        return EXIT_FAILURE;
    }

// Loop Nanosleep Until Total Interval Has Pass
// can cause eccentricity < linux kernel 2.6
    for(int s = 0; ; request = remain) {
        if((s = nanosleep(&request, &remain)) && errno != EINTR) { // sleep
            std::perror("nanosleep");
            return EXIT_FAILURE;
        }

        // Get Finish Time
        if(gettimeofday(&finish, NULL)) {
            std::perror("gettimeofday");
            return EXIT_FAILURE;
        }

        // Print
        printf("\nSlept for: %9.6f secs\n", finish.tv_sec - start.tv_sec + (finish.tv_usec - start.tv_usec) / 1000000.0);
        if(!s) break; // break on 0
        printf("Remaining: %2ld.%09ld\n", (long)remain.tv_sec, remain.tv_nsec);
    }

// End
    printf("Sleep complete\n");
    return EXIT_SUCCESS;
}

