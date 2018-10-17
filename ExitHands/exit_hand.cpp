// Get on_exit() declaration from <stdlib.h>
#define _BSD_SOURCE

#include <cstdlib>
#include <cstdio>

static void atexitFunc1() { printf("atexit function 1 called\n"); }
static void atexitFunc2() { printf("atexit function 2 called\n"); }
static void onexitFunc(int exitStatus, void *arg) {
    printf("on_exit function called: status=%d, arg=%ld\n", exitStatus, (long)arg);
}

int main() {
    if(on_exit(onexitFunc, (void*)10)) {
        std::perror("on_exit - 1");
        return EXIT_FAILURE;
    }
    if(atexit(atexitFunc1)) {
        std::perror("atexit - 1");
        return EXIT_FAILURE;
    }
    if(atexit(atexitFunc2)) {
        std::perror("atexit - 2");
        return EXIT_FAILURE;
    }
    if(on_exit(onexitFunc, (void*)20)) {
        std::perror("on_exit - 2");
        return EXIT_FAILURE;
    }

    exit(2);
}

