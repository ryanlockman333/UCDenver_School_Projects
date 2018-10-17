#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <signal.h>
#include <unistd.h>

// Counts Signals Delivered
static int sigCnt[NSIG];

// Set non zero if SIGINT delivered
static volatile sig_atomic_t gotSigint = 0;

// Function Prototypes
void printSigset(FILE *of, const char *prefix, const sigset_t *sigset);

// Static Function Prototypes
static void handler(int sig);

// Main
int main(int argc, char *argv[]) {
    // Declarations
    sigset_t pendingMask, blockingMask, emptyMask;

    // Out PID
    std::cout << "\nPID: " << argv[0] << ": " << getpid();

    // Use Same Handler All Signals   
    for(int n = 1; n < NSIG; ++n)
        (void)signal(n, handler); // ignore errors
        
    // Sleep if Specified and Block All Signals
    if(argc > 1) {
        int numSecs = std::atoi(argv[1]);

        // Fill Our Blocking Signal Mask
        sigfillset(&blockingMask);
        
        // Set Process Signal Mask to Block All
        if(sigprocmask(SIG_SETMASK, &blockingMask, NULL) == -1) {
            std::cerr << "\nsigprocmask error\n";
            return EXIT_FAILURE;
        }
       
        // Verbose Sleep
        std::cout << '\n' << argv[0] << ": sleeping for: " << numSecs;
        std::fflush(stdout);
        if(sleep(numSecs) != 0) {
            std::cerr << "\nsleep error";
            return EXIT_FAILURE;
        }
        
        // Signal Pending
        if(sigpending(&pendingMask) == -1) {
            std::cerr << "\nsigpending error\n";
            return EXIT_FAILURE;
        }
        
        // Print Pending Signals
        std::cout << "\n\nPending signals are: \n" <<  argv[0] << ":\n";
        printSigset(stdout, "\t\t", &pendingMask);

        // Empty Signal Mask
        sigemptyset(&emptyMask);

        // Unblock All Signals in Process Signal Mask
        if(sigprocmask(SIG_SETMASK, &emptyMask, NULL) == -1) {
            std::cerr << "\nsigprocmask error\n";
            return EXIT_FAILURE;
        }
    }
    
    // Loop Until SIGINT Caught
    std::fflush(stdout);
    while(!gotSigint);
        
    // Display Signals Numbers Received       
    for(int n = 1; n < NSIG; ++n)
        if(sigCnt[n] != 0)
            std::cout << '\n' << argv[0] << ": signal " << n << " caught " << sigCnt[n] << " time"
                      << (sigCnt[n] == 1 ? "" : "s");
  
    std::cout << std::endl;
    return EXIT_SUCCESS;
} // End Main

// Function Implementaions
void printSigset(FILE *of, const char *prefix, const sigset_t *sigset) {
    unsigned i = 0;
    for(int sig = 1; sig < NSIG; ++sig) {
        if(sigismember(sigset, sig)) {
            ++i;
            fprintf(of, "%s%d (%s)\n", prefix, sig, strsignal(sig));
        }
    }

    if(i == 0)
        fprintf(of, "%s<empty signal set>\n", prefix);
}

void handler(int sig, siginfo_t *si, void *ucontext) {
    if(sig == SIGINT)
        gotSigint = 1;
    else
        sigCnt[sig]++;
}

