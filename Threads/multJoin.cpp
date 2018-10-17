/* 
 * Multijoin specified amount of threads through mutual exclusion.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

// Headers
#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cerrno>
#include <pthread.h>
#include <unistd.h>

// Static Globals
// Strat of Protected Variables>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
static pthread_cond_t  tDiedCond = PTHREAD_COND_INITIALIZER;  // condition variable
static pthread_mutex_t tMutex    = PTHREAD_MUTEX_INITIALIZER; // protects global variables

// Pridicates for Conditons
static std::size_t numLive     = 0, // Total threads alive or terminated and not joined
                   numUnjoined = 0; // number of terminated threads not joined

// Enumerations
enum tstate {                       // Thread States
    TS_ALIVE,                       // thread alive
    TS_TERMINATED,                  // thread terminated, not joined
    TS_JOINED                       // thread terminated, joined
};

// Structs
static struct tinfo_t {             // Info On Each Thread
    pthread_t tid;                  // thread ID
    enum tstate state;              // thread state (TS_* constants above)
    int sleepTime;                  // number of seconds to live before terminating
} *tinfo; /* declaration used only by main thread, otherwise race conditions play out */

// End of Protected Variables<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<


// Static Global Functions
static void* threadFunc(void *arg) { // start of thread
    // Get Arg Info
    tinfo_t *tptr = (tinfo_t*)arg;
    std::size_t i = tptr - tinfo;    // obtain index in tinfo array
    
    // Debug
    /*std::cout << "\nI: " << i
              << "\ntptr: " << tptr
              << "\ntinfo: " << tinfo; */
    
    // Simulate Workload
    sleep(tptr->sleepTime);

    // Aquire Lock, entering critical code>>>>>>>>>>>
    int s = 0;
    if((s = pthread_mutex_lock(&tMutex))) {
        errno = s;
        std::perror("pthread_mutex_lock");
        return (void*)EXIT_FAILURE;
    }
    std::cout << "\nThread " << i+1 << ":    Aquired Lock";

    // Manipulate Globals
    ++numUnjoined;
    tptr->state = TS_TERMINATED;

    // Release Lock, exiting critical code<<<<<<<<<<<
    if((s = pthread_mutex_unlock(&tMutex))) {
        errno = s;
        std::perror("pthread_mutex_unlock");
        return (void*)EXIT_FAILURE;
    }
    std::cout << "\nThread " << i+1 << ":    Relesed Lock";
    
    // Signal Condition State
    if((s = pthread_cond_signal(&tDiedCond))) {
        errno = s;
        std::perror("pthread_cond_signal");
        return (void*)EXIT_FAILURE;
    }
    std::cout << "\nThread " << i+1 << ":    Condition Signaled";
    
    // Success
    std::cout << "\nThread " << i+1 << ":    Terminated";
    return NULL;
} // end of thread

// Main Program
int main(int argc, char **argv) {
    // Check Args
    if(argc < 2 || !std::strcmp(argv[1], "-h")) {
        std::cerr << "\nUsage: " << argv[0] << " [secs-per-thread]...\n\n";
        return EXIT_FAILURE;
    }

    // Set Args
    const std::size_t totThreads = argc-1;
    numLive = totThreads;
    int s = 0;
    if(!(tinfo = (tinfo_t*)std::calloc(totThreads, sizeof(*tinfo)))) { /* cant use new */
        std::cerr << "\nnew\n";
        return EXIT_FAILURE;
    }

    // Loop To Create All Threads
    for(std::size_t i = 0; i < totThreads; ++i) {
        // Set Up Initial Thread Info
        tinfo[i].sleepTime = std::atoi(argv[i+1]);
        tinfo[i].state     = TS_ALIVE;

        // Create Thread
        if((s = pthread_create(&tinfo[i].tid, NULL, threadFunc, (void*)&tinfo[i]))) {
            errno = s;
            std::perror("pthread_create");
            return EXIT_FAILURE;
        }
    }

    // Join Terminated Threads
    while(numLive > 0) {
        // Aquire Lock, entering critical code>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
        if((s = pthread_mutex_lock(&tMutex))) {
            errno = s;
            std::perror("pthread_mutex_lock");
            return EXIT_FAILURE;
        }
        std::cout << "\nMain Thread: Aquired Lock";

        // Wait for Condition State Change Signal
        /* restart incase of spurious starts or other threads changing predicate state */
        std::cout << "\nMain Thread: Waiting ";
        while(!numUnjoined) // == 0 predicate
            if((s = pthread_cond_wait(&tDiedCond, &tMutex))) {
                errno = s;
                std::perror("pthread_cond_wait");
                return EXIT_FAILURE;
            }
            else
                std::cout << "\nMain Thread: Received Conditon Signal";

        // Loop to Consume All State Changes
        for(std::size_t i = 0; i < totThreads; ++i) {
            // Check Termination State
            if(tinfo[i].state == TS_TERMINATED) {
                // Join Thread
                if((s = pthread_join(tinfo[i].tid, NULL))) {
                    errno = s;
                    std::perror("pthread_join");
                    return EXIT_FAILURE;
                }
                std::cout << "\nMain Thread: Joined Thread: " << i+1;

                // Mark State As Joined and Decrement Globals
                tinfo[i].state = TS_JOINED;
                --numLive, --numUnjoined;

                // Print Activity
                std::cout << "\nMain Thread: Reaped " << i+1 << " (Alive=" << numLive << ')';
            }
        }

        // Release Lock, exiting critical code<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
        if((s = pthread_mutex_unlock(&tMutex))) {
            errno = s;
            std::perror("pthread_mutex_unlock");
            return EXIT_FAILURE;
        }
        std::cout << "\nMain Thread: Release Lock";
    } // end while

    // Success
    std::cout << "\n\n";
    return EXIT_SUCCESS;
}

