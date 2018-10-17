// Headers
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <csignal>
#include <cstring>
#include <cerrno>
#include <ctime>
#include <sys/wait.h>
#include <unistd.h>

// Defines
#define BUF_SIZE 256

// Static Globals
static volatile int numLiveChildren = 0;

// Static Functions
static char* currTime(const char *format) { // non-reentrant
    // Get Time
    std::time_t t = std::time(NULL);
    tm *tm        = std::localtime(&t);
    if(!tm)
        return NULL;
    
    // Format Time
    static char buf[BUF_SIZE];
    std::size_t s = std::strftime(buf, BUF_SIZE, format ? format : "%c", tm);

    return !s ? NULL : buf;
}

/* std::cout is non-reentrant, so this function is alos non-reentrant,
 * should not be used in a signal handler (non-async-signal-safe) */
static void printWaitStatus(const std::string *const msg, const int status) {
    // Print Optional Message
    if(msg)
        std::cout << msg;

    // Child Exited Normally, Probe Exit Status(lower 8 byts(0-255))
    if(WIFEXITED(status))
        std::cout << "\nChild Exited: Status: " << WEXITSTATUS(status);
    // Child Killed By A Signal, Probe Exit Signal Number And Core Dump
    else if(WIFSIGNALED(status)) {
        std::cout << "\nChild Killed: Signal: " << WTERMSIG(status)
                  << " (" << strsignal(WTERMSIG(status)) << ')';
        
        /* Not in SUSv3, may be absent on some systems */
        #ifdef WCOREDUMP
        if(WCOREDUMP(status))
            std::cout << " (core dumped)";
        #endif
    }
    // Child Stopped By A Signal, Probe Stop Signal Number
    else if(WIFSTOPPED(status))
        std::cout << "\nChild Stopped: Signal: " << WSTOPSIG(status)
                  << " (" <<  strsignal(WSTOPSIG(status)) << ')';
    // Child Continued By A Signal
    /* SUSv3 has this, but older Linux versions and some other UNIX implementations don't */   
    #ifdef WIFCONTINUED 
    else if(WIFCONTINUED(status))
        std::cout << "\nChild Continued: Signal: (" << strsignal(SIGCONT) << ')';
    #endif
    // Shouldn't Get Here
    else
        std::cout << "\nChild Is Missing? (status: " << (unsigned)status << ')';
}

static void reaper(int sig) {
    int savedErrno = errno, status = 0;

    std::cout << '\n' << currTime("%T") << " Handler: Caught SIGCHLD";

    pid_t cPid = 0;
    while((cPid = waitpid(-1, &status, WNOHANG)) > 0) {
        std::cout << '\n' << currTime("%T") << " Handler: Reaped Child: " << cPid;
        printWaitStatus(NULL, status);
        numLiveChildren--;
    }

    if(cPid == -1 && errno != ECHILD)
        std::perror("waitpid");

    sleep(5);
    std::cout << '\n' << currTime("%T") << " Handler: Returning";
    errno = savedErrno;
}

// Main
int main(int argc, char **argv) {
    // CHeck Args
    if(argc < 2 || !std::strcmp(argv[1], "-h")) {
        std::cerr << "\nUsage: " << argv[0] << " [child-sleep-time]...\n\n";
        return EXIT_FAILURE;
    }

    // Disable Buffering
    setbuf(stdout, NULL);

    // Set Child Count
    numLiveChildren = argc-1;
    
    // Set Up Handler for Catching Zombie Children
    struct sigaction sa;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags   = 0;
    sa.sa_handler = reaper;

    if(sigaction(SIGCHLD, &sa, NULL)) {
        std::perror("sigaction");
        return EXIT_FAILURE;
    }

    // Block SIGCHLD Incase Early Termination of Child Before sigsuspend
    sigset_t blockMask;
    sigemptyset(&blockMask);
    sigaddset(&blockMask, SIGCHLD);

    if(sigprocmask(SIG_SETMASK, &blockMask, NULL)) {
        std::perror("sigprocmask");
        return EXIT_FAILURE;
    }

    // Loop Child Creation
    for(int i = 1; i < argc; ++i)
        switch(fork()) {
        // Error
        case -1:
            std::perror("fork");
            return EXIT_FAILURE;
        // Child
        case 0:
            // Sleep Related to Cmd Args
            if(sleep(std::atoi(argv[i])))
                std::perror("sleep");

            // Print Child Info
            std::cout << '\n' << currTime("%T") << " Child " << i << ": PID " << getpid() << ": Exiting";
            
            _exit(EXIT_SUCCESS);
        default:
            break;
        }

    // Use Empty Mask During Suspend(unblock all)
    sigset_t emptyMask;
    sigemptyset(&emptyMask);

    // Suspend Process Until Signal Delivery
    unsigned sigCnt = 0;
    for(; numLiveChildren > 0; ++sigCnt)
        if(sigsuspend(&emptyMask) && errno != EINTR) { // returns after sighand
            std::perror("sigsuspend");
            return EXIT_FAILURE;
        }

    // Print Info
    std::cout << '\n' << currTime("%T") << " All "<< argc-1 << " Children Died"
              << "\nSIGCHLD Caught: " << sigCnt << ' ' << (sigCnt == 1 ? "time\n\n" : "times\n\n");
    return EXIT_SUCCESS;
}

