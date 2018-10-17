#include <cstdlib>
#include <cstdio>
#include <cerrno>
#include <pthread.h>
#include "strerr_tunsafe.h"

static void* threadFunc(void *arg) {
    printf("Other thread about to call strerror()\n");
    char *str = strerror(EPERM);
    printf("Other thread: str (%p) = %s\n", str, str);
    return NULL;
}

int main(int argc, char **argv) {
    pthread_t t;
    char *str = strerror(EINVAL);
    printf("Main  thread has called strerror()\n");
   
    int s = pthread_create(&t, NULL, threadFunc, NULL);
    if(s) {
        errno = s;
        std::perror("pthread_create");
        return EXIT_FAILURE;
    }
    
    if((s = pthread_join(t, NULL))) {
        errno = s;
        std::perror("pthread_join");
        return EXIT_FAILURE;
    }

    printf("Main  thread: str (%p) = %s\n", str, str);
    return EXIT_SUCCESS;
}

