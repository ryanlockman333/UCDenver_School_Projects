#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cerrno>
#include <pthread.h>

static void *threadFunc(void *arg) {
    char *s = (char*)arg;
    std::cout << s;
    return (void*)std::strlen(s);
}

int main(int argc, char **argv) {
    // Create Thread
    pthread_t t1;
    int s = pthread_create(&t1, NULL, threadFunc, (void*)"\nHello world");
    if(s) {
        errno = s;
        std::perror("pthread_create");
        return EXIT_FAILURE;
    }

    // Main Msg, could print after thread returns(hello world) depending on kernel thread schedualing(race condition)
    std::cout << "\nMessage from main()";
    
    // Wait to Join
    void *res = NULL;
    if((s = pthread_join(t1, &res))) {
        errno = s;
        std::perror("pthread_join");
        return EXIT_FAILURE;
    }
    std::cout << "\nThread Returned: " << (long)res << '\n';

    return EXIT_SUCCESS;
}

