#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <cerrno>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/syscall.h>

// Initialize Static Lock and Condition Variable
static pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
static int avail = 0; // predicate associated with condition

static void* threadFunc(void *arg) {
    /*  Depending on size of arg, multiple threads will be blocking for lock */
    // Loop Number of Times Specified, being equal to totRequired
    for(int i = 0, s = 0, loops = std::atoi((char*)arg); i < loops; ++i) {
        sleep(1);

        /* Code to produce a unit omitted */

        // Aquire Lock
        if((s = pthread_mutex_lock(&mtx))) {
            errno = s;
            std::perror("pthread_mutex_lock");
            return (void*)EXIT_FAILURE;
        }
        std::cout << "\nThread:      " << (long)pthread_self() << ": Lock Aquired";
        //std::cout << "\nThread: " << (long)syscall(SYS_gettid) << ": Lock Aquired";
        std::fflush(stdout);

        ++avail; // Let Consumer Know a Unit is Available

        // Release Lock
        std::cout << "\nThread:      " << (long)pthread_self() << ": Lock Released";
        std::fflush(stdout);
        if((s = pthread_mutex_unlock(&mtx))) {
            errno = s;
            std::perror("pthread_mutex_unlock");
            return (void*)EXIT_FAILURE;
        }

        // Signal Sleeping Consumer
        std::cout << "\nThread:      " << (long)pthread_self() << ": Conditon Signaled";
        std::fflush(stdout);    
        if((s = pthread_cond_signal(&cond))) {
            errno = s;
            std::perror("pthread_cond_signal");
            return (void*)EXIT_FAILURE;
        }  
    }
    return NULL;
}

int main(int argc, char **argv) {
    // Start Time Point
    std::time_t t = std::time(NULL);

    // Check Args
    if(argc < 2) {
        std::cerr << "\nUsage: " << argv[0] << " [units-per-thread...]\n\n";
        return EXIT_FAILURE;
    }

    // Create All Threads
    pthread_t tid;
    int totRequired = 0, s = 0;
    for(int i = 1; i < argc; ++i) {
        totRequired += std::atoi(argv[i]); // total to consume

        // Create
        if((s = pthread_create(&tid, NULL, threadFunc, (void*)argv[i]))) {
            errno = s;
            std::perror("pthread_create");
            return EXIT_FAILURE;
        }
    }
    std::cout << std::endl;

    /* Threads might still blocking(depending on args) for locks by the time we poll */

    // Use a Polling Loop to Check for Available Units
    int numConsumed = 0;
    for(bool done = false; !done;) {
        // Aquire Lock, start critical code>>>>>>>>>>>>>>>>>>>>>>>>>
        if((s = pthread_mutex_lock(&mtx))) {
            errno = s;
            std::perror("pthread_mutex_lock");
            return EXIT_FAILURE;
        }
        std::cout << "\nMain Thread: " << (long)pthread_self() << ": Lock Aquired";
        std::fflush(stdout);

        // Wait to Consume our Food
        /* pthread_cond_wait should be in a while loop instead of an if because there are no
           garentees on predicates state after it returns(e.g. spurrios wakeups and other threads
           wakeing first which might change the prdicate, so a recheck is required */
        std::cout << "\nMain Thread: " << (long)pthread_self() << ": Waiting";
        while(!avail) // while avail == 0 (e.g. !(!0)) This is Our Predicate
            if((s = pthread_cond_wait(&cond, &mtx))) { // block until condition becomes available
                errno = s;
                std::perror("pthread_cond_wait");
                return EXIT_FAILURE;
            }
            else
                std::cout << "\nMain Thread: " << (long)pthread_self() << ": Condition Received";           


        /* At this point, 'mtx' is locked... */

        // Consume All Available Units nom..nom...
        while(avail > 0) {
            /* Do something with produced unit */

            // Decrement Available Units, Increment Consumed
            ++numConsumed;
            --avail;

            std::cout << "\nMain Thread: " << (long)pthread_self() << ": Time: "
                      << (long)(std::time(NULL)-t) << " secs: Consumed: " << numConsumed;
            std::fflush(stdout);
            done = numConsumed >= totRequired; // check if consumed all
        }

        // Release Lock, <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<end critical code
        std::cout << "\nMain Thread: " << (long)pthread_self() << ": Lock Released";
        std::fflush(stdout);
        if((s = pthread_mutex_unlock(&mtx))) {
            errno = s;
            std::perror("pthread_mutex_unlock");
            return EXIT_FAILURE;
        }

        /* Perhaps do other work here that does not require mutex lock */

    }

    std::cout << "\n\n";
    return EXIT_SUCCESS;
}

