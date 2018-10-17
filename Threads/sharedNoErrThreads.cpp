#include <cstdlib>
#include <cstdio>
#include <cerrno>
#include <pthread.h>

static volatile int glob = 0; /* "volatile" prevents compiler optimizations
                                 of arithmetic operations on 'glob' */
static pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;

static void* threadFunc(void *arg) {
    for(int i  = 0, s = 0, loops = *((int*)arg); i < loops; ++i) {
        if((s = pthread_mutex_lock(&mtx))) {
            errno = s;
            std::perror("pthread_mutex_lock");
            exit(EXIT_FAILURE);
        }

        int loc = glob;
        ++loc;
        glob = loc;
        
        if((s = pthread_mutex_unlock(&mtx))) {
            errno = s;
            std::perror("pthread_mutex_unlock");
            exit(EXIT_FAILURE);
        }
    }    
    return NULL;
}

int main(int argc, char **argv) {
    pthread_t t1, t2;
    int loops = (argc > 1) ? std::atoi(argv[1]) : 10000000;
    
    int s = pthread_create(&t1, NULL, threadFunc, &loops);
    if(s) {
        errno = s;
        std::perror("pthread_create");
        return EXIT_FAILURE;
    }

    if((s = pthread_create(&t2, NULL, threadFunc, &loops))) {
        errno = s;
        std::perror("pthread_create");
        return EXIT_FAILURE;
    }

    if((s = pthread_join(t1, NULL))) {
        errno = s;
        std::perror("pthread_join");
        return EXIT_FAILURE;
    }

    if((s = pthread_join(t2, NULL))) {
        errno = s;
        std::perror("pthread_join");
        return EXIT_FAILURE;
    }

    printf("glob = %d\n", glob);
    return EXIT_SUCCESS;
}

