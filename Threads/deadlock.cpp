#include <cstdlib>
#include <cstdio>
#include <cerrno>
#include <pthread.h>
#include <unistd.h>

static int glob1 = 0, glob2 = 0;
static pthread_mutex_t mtx1 = PTHREAD_MUTEX_INITIALIZER,
                       mtx2 = PTHREAD_MUTEX_INITIALIZER;

static void* threadFunc1(void *arg) {
    for(int i  = 0, s = 0, loops = *((int*)arg); i < loops; ++i) {
        if((s = pthread_mutex_lock(&mtx1))) {
            errno = s;
            std::perror("pthread_mutex_lock");
            pthread_exit((void*)EXIT_FAILURE);
        }
        
        //sleep(10); put unlock mtx before second lock, and sleep produces deadlock also
        int loc1 = glob1;
        ++loc1;
        glob1 = loc1;
        
        if((s = pthread_mutex_lock(&mtx2))) { // can do a trylock here and if it fails with EBUSY then free all locks
            errno = s;
            std::perror("pthread_mutex_lock");
            pthread_exit((void*)EXIT_FAILURE);
        }

        int loc2 = glob2;
        ++loc2;
        glob2 = loc2;
        
        if((s = pthread_mutex_unlock(&mtx1))) {
            errno = s;
            std::perror("pthread_mutex_unlock");
            pthread_exit((void*)EXIT_FAILURE);
        }
        
        if((s = pthread_mutex_unlock(&mtx2))) {
            errno = s;
            std::perror("pthread_mutex_unlock");
            pthread_exit((void*)EXIT_FAILURE);
        }
    }    
    return NULL;
}

static void* threadFunc2(void *arg) {
    for(int i  = 0, s = 0, loops = *((int*)arg); i < loops; ++i) {
        if((s = pthread_mutex_lock(&mtx2))) {
            errno = s;
            std::perror("pthread_mutex_lock");
            pthread_exit((void*)EXIT_FAILURE);
        }

        int loc = glob2;
        ++loc;
        glob2 = loc;

        // put unlock mtx before second lock, and sleep above cause deadlock

        if((s = pthread_mutex_lock(&mtx1))) { // can do a trylock here and if it fails with EBUSY then free all locks
            errno = s;
            std::perror("pthread_mutex_lock");
            pthread_exit((void*)EXIT_FAILURE);
        }

        int loc1 = glob1;
        ++loc1;
        glob1 = loc1;
        
        if((s = pthread_mutex_unlock(&mtx2))) {
            errno = s;
            std::perror("pthread_mutex_unlock");
            pthread_exit((void*)EXIT_FAILURE);
        }

        if((s = pthread_mutex_unlock(&mtx1))) {
            errno = s;
            std::perror("pthread_mutex_unlock");
            pthread_exit((void*)EXIT_FAILURE);
        }

    }    
    return NULL;
}

int main(int argc, char **argv) {
    pthread_t t1, t2;
    int loops = (argc > 1) ? std::atoi(argv[1]) : 10000000;
    
    int s = pthread_create(&t1, NULL, threadFunc1, &loops);
    if(s) {
        errno = s;
        std::perror("pthread_create");
        return EXIT_FAILURE;
    }

    if((s = pthread_create(&t2, NULL, threadFunc2, &loops))) {
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

    printf("glob1 = %d\n", glob1);
    printf("glob2 = %d\n", glob2);
    return EXIT_SUCCESS;
}

