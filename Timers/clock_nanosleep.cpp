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

// Functions
static void sigintHandler(int sig) {}

// Main
int main(int argc, char **argv) {
// Check Args
    if(argc != 2 || !std::strcmp(argv[1], "-h")) {
        std::cerr << '\n' << argv[0] << " [secs]\n\n";
        return EXIT_FAILURE;
    }

// Declarations
    timespec request;

// Get Current CLOCK_REALTIME(wall-clock) Value
    if(clock_gettime(CLOCK_REALTIME, &request)) {
        std::perror("clock_gettime");
        return EXIT_FAILURE;
    }

// Add Requested Timespec
    request.tv_sec += std::atol(argv[1]);
    //request.tv_nsec = std::atol(argv[2]);

// Set Up Signal Handler
    struct sigaction sa;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sa.sa_handler = sigintHandler;

    if(sigaction(SIGINT, &sa, NULL)) {
        std::perror("sigaction");
        return EXIT_FAILURE;
    }


// Loop Nanosleep Until Total Interval Has Pass
    printf("Sleeping.....\n");
    for(int s = 0;;) 
        if((s = clock_nanosleep(CLOCK_REALTIME, TIMER_ABSTIME, &request, NULL))) { // sleep
            if(s == EINTR)
                printf("\nInterupted by a Signal Handler\n");
            else {
                std::perror("nanosleep");
                return EXIT_FAILURE;
            }
        }
        else if(!s)
            break;

// End
    printf("Sleep complete\n");
    return EXIT_SUCCESS;
}

