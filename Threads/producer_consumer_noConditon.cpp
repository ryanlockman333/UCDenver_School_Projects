#include <cstdio>
#include <cstdlib>
#include <cerrno>
#include <ctime>
#include <pthread.h>
#include <unistd.h>

static pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
static int avail = 0;

static void* threadFunc(void *arg) {
    int cnt = std::atoi((char*)arg);
    int s = 0;
    for(int i = 0; i < cnt; ++i) {
        sleep(1);

        /* Code to produce a unit omitted */

        // Aquire Lock
        if((s = pthread_mutex_lock(&mtx))) {
            errno = s;
            std::perror("pthread_mutex_lock");
            pthread_exit((void*)EXIT_FAILURE);
        }

        ++avail; // Let consumer know another unit is available

        // Release Lock
        if((s = pthread_mutex_unlock(&mtx))) {
            errno = s;
            std::perror("pthread_mutex_unlock");
            pthread_exit((void*)EXIT_FAILURE);
        }
    }
    return NULL;
}

int main(int argc, char **argv) {
    std::time_t t = std::time(NULL); // initialize start time

    // Check Args
    if(argc < 2) {
        printf("Usage: ./pName [units-per-thread...]\n\n");
        return EXIT_FAILURE;
    }

    // Create All Threads
    pthread_t tid;
    int totRequired = 0; // Total number of units that all threads will produce
    int s = 0;
    for(int i = 1; i < argc; ++i) {
        totRequired += std::atoi(argv[i]); // update

        // Create
        if((s = pthread_create(&tid, NULL, threadFunc, argv[i]))) {
            errno = s;
            std::perror("pthread_create");
            return EXIT_FAILURE;
        }
    }

    // Use a Polling(return immediatley) Loop to Check for Available Units
    int numConsumed = 0; // total units consumed so far
    bool done = false;
    for(;;) {
        // Aquire Lock
        if((s = pthread_mutex_lock(&mtx))) {
            errno = s;
            std::perror("pthread_mutex_lock");
            return EXIT_FAILURE;
        }
        
        // Consume all available units
        while(avail > 0) {
            /* Do something with produced unit */

            ++numConsumed;
            --avail;

            printf("T=%ld: numConsumed=%d\n", (long)(std::time(NULL)-t), numConsumed); 
            done = numConsumed >= totRequired; // check if all consumed
        }

        // Release Lock
        if((s = pthread_mutex_unlock(&mtx))) {
            errno = s;
            std::perror("pthread_mutex_unlock");
            return EXIT_FAILURE;
        }

        // Break on Done
        if(done)
            break;

        /* Perhaps do other work here that does not require mutex lock */
    }

    return EXIT_SUCCESS;
}

