#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

//#define _POSIX_C_SOURCE >= 199309L

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <signal.h>
#include <unistd.h>
#include <ucontext.h>

static void sigsegvHandler(int sig, siginfo_t *si, void *ucontext) {
    int x = 0;
    
    printf("Caught signal %d (%s)\n", sig, strsignal(sig));
    printf("Top of handler stack near %10p\n", (void*)&x);
    fflush(NULL);
    _exit(EXIT_FAILURE); /* Can't return after SIGSEGV */
}

static void overflowStack(int callNum) { /* A recursive function that overflows the stack */
    char a[100000]; /* Make this stack frame large */

    printf("Call %4d - top of stack near %10p\n", callNum, &a[0]);
    overflowStack(callNum+1);
}

int main(int argc, char *argv[]) {
    stack_t sigstack;
    struct sigaction sa;
    int j = 0;

    printf("Top of standard stack is near %10p\n", (void*)&j);
    
    /* Allocate alternate stack and inform kernel of its existence */
    sigstack.ss_sp = malloc(SIGSTKSZ);

    if(!sigstack.ss_sp) {
        std::cerr << "\nmalloc error\n";
        return EXIT_FAILURE;
    }

    sigstack.ss_size = SIGSTKSZ;
    sigstack.ss_flags = 0;

    if(sigaltstack(&sigstack, NULL)) { // if == -1
        std::perror("signalstack");
        return EXIT_FAILURE;
    }

    printf("Alternate stack is at %10p-%p\n", sigstack.ss_sp, (char*)sbrk(0) - 1);
    sa.sa_sigaction = sigsegvHandler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_ONSTACK; /* Handler uses alternate stack */

    if(sigaction(SIGSEGV, &sa, NULL)) { // if == -1
        std::perror("sigaction");
        return EXIT_FAILURE;
    }
    
    overflowStack(1);
}

