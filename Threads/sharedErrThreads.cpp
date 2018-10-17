#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cerrno>
#include <pthread.h>
// increment error
static volatile int glob = 0; // volatile makes it 'more' incorrect, without it the output is
                              // determined by both the kernels CPU scheduling decisions and
                              // the compilers optimization decisions
                              /* "volatile" prevents compiler optimizations
                                   of arithmetic operations on 'glob' */
static void* threadFunc(void *arg) {
    int loops = *((int *) arg);
    int loc, j;
    for(j = 0; j < loops; j++) {
        loc = glob;
        loc++;
        glob = loc;
    }
    return NULL;
}

int main(int argc, char *argv[]) {
    pthread_t t1, t2;
    int loops = argc > 1 ? std::atoi(argv[1]) : 10000000, s = 0;
    
    if((s = pthread_create(&t1, NULL, threadFunc, &loops))) {
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

