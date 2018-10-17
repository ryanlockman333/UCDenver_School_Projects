// Defines
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <csignal>
#include <cstring>
#include <ctime>
#include <unistd.h>

// Defines
#define TIMER_SIG SIGRTMAX
#define BUF_SIZE 1024

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

char* currTime(const char *format) { // non-reentrant
    static char buf[BUF_SIZE];
    std::time_t t = std::time(NULL);
    tm *tm = std::localtime(&t);
    
    if(!tm)
        return NULL;

    std::size_t s = std::strftime(buf, BUF_SIZE, format ? format : "%c", tm);

    return !s ? NULL : buf;
}

static void handler(int sig, siginfo_t *si, void *uc) {
    timer_t tidptr = si->si_value.sival_ptr;

    // Print(Unsafe)
    printf("\n[%s] Got signal %d\n", currTime("%T"), sig);
    printf("   *sival_ptr         = %ld\n", (long)tidptr);
    printf("   timer_getoverrun() = %d\n", timer_getoverrun(tidptr));
}

// Main
int main(int argc, char **argv) {
// Check Args
    if(argc < 2 || !std::strcmp(argv[1], "-h")) {
        std::cerr << "\nUsage: " << argv[0] << " [timer-secs]:[interval-secs]...\n\n";
        return EXIT_FAILURE;
    }

    timer_t *tidlist = (void**)std::calloc(argc-1, sizeof(timer_t));
    if(!tidlist) {
        std::perror("malloc");
        return EXIT_FAILURE;
    }

// Set Up Signal Handler
    struct sigaction sa;
    sa.sa_flags     = SA_SIGINFO;
    sa.sa_sigaction = handler;
    sigemptyset(&sa.sa_mask);
    
    if(sigaction(TIMER_SIG, &sa, NULL)) {
        std::perror("sigaction");
        return EXIT_FAILURE;
    }

// Set Up Signal Event
    sigevent sev;
    sev.sigev_notify = SIGEV_SIGNAL; // notify via sig
    sev.sigev_signo  = TIMER_SIG;    // notify via this sig
    
// Loop Conversion/Create/Arm 
    itimerspec ts;
    for(int i = 0; i < argc-1; ++i) {
        // Convert Cmd Args into itimespec Structs
        itimerspecFromStr(argv[i+1], &ts);
        sev.sigev_value.sival_ptr = &tidlist[i]; // allow handler to get id

        // Create Timer and Print
        if(timer_create(CLOCK_REALTIME, &sev, &tidlist[i])) {
            std::perror("timer_create");
            return EXIT_FAILURE;
        }
        printf("Timer ID: %ld (%s)\n", (long)tidlist[i], argv[i+1]);
    
        // Arm Timer
        if(timer_settime(tidlist[i], 0, &ts, NULL)) {
            std::perror("timer_settime");
            return EXIT_FAILURE;
        }
    }
    
// Wait for Signals
    for(;;)
        pause();

// End
    return EXIT_FAILURE; // shouldnt get here
}

