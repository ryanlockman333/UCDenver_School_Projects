// Headers
#include <iostream>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cerrno>
#include <cstring>
#include <unistd.h>
#include <sys/wait.h>

// Defines
#define BUF_SIZE 1024

// Function
char* currTime(const char *format) { // non-reentrant
    static char buf[BUF_SIZE];
    std::time_t t = std::time(NULL);
    tm *tm = std::localtime(&t);
    
    if(!tm)
        return NULL;

    std::size_t s = std::strftime(buf, BUF_SIZE, format ? format : "%c", tm);

    return !s ? NULL : buf;
}

// Main
int main(int argc, char **argv) {
// Check Args
    if(argc < 2 || !std::strcmp(argv[1], "-h")) {
        std::cerr << "\nUsage: " << argv[0] << " [sleep-time]...\n\n";
        return EXIT_FAILURE;
    }

// Disable stdout Buffering
    setbuf(stdout, NULL);

// Fork Children == argv's
    for(int i  = 1; i < argc; ++i) {
        switch(fork()) { 
        // Error
        case -1: 
            std::perror("fork");
            return EXIT_FAILURE;
        // Child
        case 0:
            printf("[%s] child %d started with PID %ld, sleeping %s " "seconds\n", currTime("%T"), i, (long)getpid(), argv[i]);
            
            // Sleep
            if(sleep(std::atoi(argv[i])))
                std::perror("sleep");
        
            // Soft Exit
            _exit(EXIT_SUCCESS);
        // Parent
        default:
            break;
        }
    }

// Loop Wait
    for(unsigned nDead = 0; ; ++nDead) {
       pid_t cPid = wait(NULL);
        if(cPid == -1) {
            if(errno == ECHILD) {
                printf("No more children - bye!\n");
                break;
            }
            else {
                std::perror("wait");
                return EXIT_FAILURE;
            }
        }
        printf("[%s] wait() returned child PID %ld (numDead=%d)\n", currTime("%T"), (long)cPid, nDead);
    }

// End
    return EXIT_SUCCESS;
}

