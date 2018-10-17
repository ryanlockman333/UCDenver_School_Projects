// Headers
#include <csignal>
#include <cstdlib>
#include <cstdio>
#include <cerrno>
#include <ctime>
#include <iostream>
#include <unistd.h>
#include <sys/types.h>

// Defines
#define SYNC_SIG SIGUSR1 // sync signal
#define BUF_SIZE 1024

// Functions
static void handler(int sig) {}

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
int main() {
// Disable Buffering stdout
    setbuf(stdout, NULL);
    
// Set Up Blocking Mask { entering critical region>>>>>>>>>>
    sigset_t blockMask, origMask;
    sigemptyset(&blockMask);
    sigaddset(&blockMask, SYNC_SIG); // block SYNC_SIG(SIGUSR1) before fork for race conditions

    if(sigprocmask(SIG_BLOCK, &blockMask, &origMask)) {
        std::perror("sigprocmask");
        return EXIT_FAILURE;
    }
    
// Set Up Handler    
    struct sigaction sa;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART; // restart
    sa.sa_handler = handler;
    
    if(sigaction(SYNC_SIG, &sa, NULL)) { // capture SYNC_SIG(SIGUSR1)
        std::perror("sigaction");
        return EXIT_FAILURE;
    }

// Fork Program Flow
    pid_t cPid = fork();
    switch(cPid) {
    // Error
    case -1:
        std::perror("fork");
        return EXIT_FAILURE;
    // Child
    case 0:
        // Child Does Work Here...
        printf("[%s %ld] Child started - doing some work\n", currTime("%T"), (long)getpid());
        if(sleep(2)) { // simulate time doing work...
            std::perror("sleep");
        }

        // Child Signals Parent Its Done
        printf("[%s %ld] Child about to signal parent\n", currTime("%T"), (long)getpid());           
        if(kill(getppid(), SYNC_SIG)) {
            std::perror("kill");
            return EXIT_FAILURE;
        }

        // Now Child Can Do Other Things...

        // Soft Exit(no stdio buf flush)
        _exit(EXIT_SUCCESS);
        // never exit with status code > 128, shell sets $? to 128+signo and is indistinguishable from that yielded when a process calls _exit()
    // Parent
    default:
        // Parent May Do Work, Then Waits On Child
        printf("[%s %ld] Parent about to wait for signal\n", currTime("%T"), (long)getpid());

        // Wait On Signal Then Print
        sigset_t emptyMask;
        sigemptyset(&emptyMask);
        if(sigsuspend(&emptyMask) && errno != EINTR) { // restarts on interuption } <<<<<<<<<<exiting critical region
            std::perror("sigsuspend");
            return EXIT_FAILURE;
        }
        printf("[%s %ld] Parent got signal\n", currTime("%T"), (long)getpid());

        // If Required, Restore Original Signal Mask
        if(sigprocmask(SIG_SETMASK, &origMask, NULL)) {
            std::perror("sigprocmask");
            return EXIT_FAILURE;
        }
            
        // Parent Carries On To Do Other Things...
        
        // Hard Exit
        return EXIT_SUCCESS;
    }

// End
    return EXIT_FAILURE; // shouldnt get here
}

