/* 
 * Compile: g++ -g -Wall -Wextra -lrt -std=c++11 timerfd.cpp -o timerfd
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

// Headers
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstdint>
#include <cstring>
#include <sys/timerfd.h>
#include <unistd.h>

// Functions
#ifndef _APPLE_
// output form "value.sec[/value.nanosec][:interval.sec[/interval.nanosec]]"
    void itimerspecFromStr(char *str, struct itimerspec *tsp) {
        char *dupstr = strdup(str);;

        char *cptr = std::strchr(dupstr, ':');
        if(cptr) 
            *cptr = '\0';

        char *sptr = std::strchr(dupstr, '/');
        if(sptr)
            *sptr = '\0';

        tsp->it_value.tv_sec  = std::atoi(dupstr);
        tsp->it_value.tv_nsec = sptr ? std::atoi(sptr+1) : 0;

        if(!cptr) {
            tsp->it_interval.tv_sec  = 0;
            tsp->it_interval.tv_nsec = 0;
        } else {
            if((sptr = std::strchr(cptr+1, '/')))
                *sptr = '\0';
        
            tsp->it_interval.tv_sec  = std::atoi(cptr+1);
            tsp->it_interval.tv_nsec = sptr ? std::atoi(sptr+1) : 0;
        }
    
        std::free(dupstr);
    }
#endif

// Main
int main(int argc, char **argv) {
// Check Args
    if(argc < 2 || !std::strcmp(argv[1], "-h")) {
        std::cerr << "\nUsage: " << argv[0] << "  [secs]:[interval-secs] [max-exp]\n\n";
        return EXIT_FAILURE;
    }

// Set Up Args
    itimerspec ts;
    itimerspecFromStr(argv[1], &ts);
   
    int maxExp = argc > 2 ? std::atoi(argv[2]) : 1;
    
// Create Timer FD and Set Time
    int fd = timerfd_create(CLOCK_REALTIME, 0);
    if(fd == -1) {
        std::perror("timerfd_create");
        return EXIT_FAILURE;
    }

    if(timerfd_settime(fd, 0, &ts, NULL)) {
        std::perror("timerfd_settime");
        return EXIT_FAILURE;
    }
    
// Get Start Time
    timespec start;
    if(clock_gettime(CLOCK_MONOTONIC, &start)) {
        std::perror("clock_gettime");
        return EXIT_FAILURE;
    }

// Loop
    timespec now;
    for(std::uint64_t totalExp = 0, numExp = 0; totalExp < (std::uint64_t)maxExp;) {
        // Read
        if(read(fd, &numExp, sizeof(std::uint64_t)) != sizeof(std::uint64_t)) {
            std::perror("read");
            return EXIT_FAILURE;
        }
        
        // Update Total
        totalExp += numExp;
        
        // Get Now Time
        if(clock_gettime(CLOCK_MONOTONIC, &now)) {
            std::perror("clock_gettime");
            return EXIT_FAILURE;
        }

        // Get Elapsed Secs and Check Nano
        int secs = now.tv_sec - start.tv_sec, nanosecs = now.tv_nsec - start.tv_nsec;
        if(nanosecs < 0) {
            --secs;
            nanosecs += 1000000000;
        }

        // Print
        printf("%d.%03d: expirations read: %llu; total=%llu\n", secs, (nanosecs+500000)/1000000,
                (unsigned long long)numExp, (unsigned long long)totalExp); // even std::cout needs (unsigned long long)
    }

// End
    return EXIT_SUCCESS;
}

