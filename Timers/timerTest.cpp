#include <iostream>
#include <csignal>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <sys/time.h>

static volatile std::sig_atomic_t gotAlarm = 0;

// Displays Elapsed Real Time(clock) Since Program Start
// Then Displays ITIMER_REAL State
static int displayTimes(const char *msg, bool includeTimer) {
    itimerval itv;
    static timeval start;
    timeval curr;
    static int callNum = 0;
    
    // Initial Start Time(0)
    if(!callNum)
        if(gettimeofday(&start, NULL)) {
            std::perror("gettimeofday");
            return -1;
        }

    // Print Header Every 20 Lns
    if(!(callNum % 20)) ///////////////// check
        std::cout << "\n       Elapsed | Value | Interval\n";

    // Get/Print Current Time(Elapsed)
    if(gettimeofday(&curr, NULL)) {
        std::perror("gettimeofday");
        return -1;
    }
    std::cout << std::showpoint << std::fixed << std::setprecision(2)
              << msg << "   "
              << curr.tv_sec - start.tv_sec + (curr.tv_usec - start.tv_usec) / 1000000.0;

    // Check Inculsion and Get/Print Value and Inteval
    if(includeTimer) {
        if(getitimer(ITIMER_REAL, &itv)) {
            std::perror("getitimer");
            return -1;
        }
        std::cout << "     " << itv.it_value.tv_sec    + itv.it_value.tv_usec    / 1000000.0
                  << "     " << itv.it_interval.tv_sec + itv.it_interval.tv_usec / 1000000.0;
    }
    
    std::cout << std::endl;
    ++callNum;
    
    return 0;
}

static void sigalrmHandler(int sig) { gotAlarm = 1; }

int main(int argc, char *argv[]) {
// Check Args
    if((argc > 1 && !std::strcmp(argv[1], "-h")) || argc > 5) {
        std::cerr << "\nUsage: " << argv[0] << " [secs] [usecs] [intv-secs] [intv-usecs]\n\n";
        return EXIT_FAILURE;
    }

// Set Up Signal Action
    struct sigaction sa;
    sigemptyset(&sa.sa_mask);
    sa.sa_handler = sigalrmHandler;
    sa.sa_flags = 0;

    if(sigaction(SIGALRM, &sa, NULL)) {
        std::perror("sigaction");
        return EXIT_FAILURE;
    }

// Set Up Real(clock) Timer
    itimerval old_itv, itv;
    itv.it_value.tv_sec     = (argc > 1) ? std::atol(argv[1]) : 2;
    itv.it_value.tv_usec    = (argc > 2) ? std::atol(argv[2]) : 0;
    itv.it_interval.tv_sec  = (argc > 3) ? std::atol(argv[3]) : 0;
    itv.it_interval.tv_usec = (argc > 4) ? std::atol(argv[4]) : 0;

    int maxSigs = old_itv.it_interval.tv_sec == 0 && old_itv.it_interval.tv_usec == 0 ? 1 : 3; // exit after 3 sigs, or 1 sig if interval is 0
    displayTimes("START:", false);

    if(setitimer(ITIMER_REAL, &itv, NULL)) {
        std::perror("setitimer");
        return EXIT_FAILURE;
    }

// Main Loop to Consume CPU Time
    int sigCnt = 0;
    for(;;) {
        std::clock_t prevClock = std::clock();

        // Inner Loop ConsumesAround 0.5 secs CPU Time       
        while(((std::clock() - prevClock) * 10 / CLOCKS_PER_SEC) < 5)
            // Check Received SIGALRM via Notifying Global Flag
            if(gotAlarm) {
                gotAlarm = 0; // reset global flag
                displayTimes("ALARM:", true); // display Alarm
                ++sigCnt;

                // Check maxSigs Upper Limit to Quit
                if(sigCnt >= maxSigs) {
                    printf("\n\nThat's all folks\n\n");
                    return EXIT_SUCCESS;
                }
            }
        
        displayTimes("Main: ", true); // display Start
    }

    // Shouldnt Get Here
    return EXIT_FAILURE;
}

