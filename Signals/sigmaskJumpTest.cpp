#ifndef _GNU_SOURCE
    #define _GNU_SOURCE
#endif

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <csetjmp>
#include <csignal>
#include <unistd.h>

// Statics
static volatile std::sig_atomic_t canJump = 0;

#ifdef USE_SIGSETJMP
    static sigjmp_buf senv;
#else
    static std::jmp_buf env;
#endif

// Static Functions
static void printSigset(std::ostream &os, const char *prefix, const sigset_t *sigset) {
    int i = 0;
    for(int sig = 1; sig < NSIG; ++sig)
        if(sigismember(sigset, sig)) {
            os << '\n' << prefix << sig << " (" << strsignal(sig) << ')';
            ++i;
        }

    if(!i)
        os << '\n' << prefix << "<empty signal set>";

    std::fflush(stdout);
}

static int printSigMask(std::ostream &os, const char *msg) {
    sigset_t currMask;
    
    if(msg)
        os << '\n' << msg;
    if(sigprocmask(SIG_BLOCK, NULL, &currMask) == -1)
        return -1;
    
    printSigset(os, "\t\t", &currMask);
    return 0;
}

static void handler(int sig, siginfo_t *si, void *ucontext) {
    std::cout << "\nReceived signal " << sig << " (" << strsignal(sig) << ')' << ", signal mask is:";
    printSigMask(std::cout, NULL);

    if(!canJump) {
        std::cout << "'env' buffer not yet set, doing a simple return";
        return;
    }

    std::cout << "\n*Signal Info Structure*"
              << "\nSignal Number:                 " << si->si_signo
              << "\nError Value:                   " << si->si_errno
              << "\nSignal Code:                   " << si->si_code
            //<< "\nTrap Number:                   " << si->si_trapno    // hardware signal (unused on most architectures)
              << "\nSender Process ID:             " << si->si_pid
              << "\nSender Real User ID:           " << si->si_uid
              << "\nExit Status or Signal:         " << si->si_status
              << "\nUser-Time Used:                " << si->si_utime / sysconf(_SC_CLK_TCK)
              << "\nSystem-Time Used:              " << si->si_stime / sysconf(_SC_CLK_TCK)
              << "\nSignal Value:                  " << si->si_value.sival_int
              << "\nPosix.1b Signal:               " << si->si_int       // posix.1b only
              << "\nPosix.1b Timer Overrun Count:  " << si->si_overrun   // posix.1b only
              << "\nPosix.1b Timer ID:             " << si->si_timerid   // posix.1b only
              << "\nMemory Location Causing Fault: " << si->si_addr
              << "\nBand Event:                    " << si->si_band
              << "\nFile Descriptor:               " << si->si_fd << "\n\n";
            //<< "\nLeast Significant Address Bit: " << si->si_addr_lsb; // >= linux 2.6.32

    #ifdef USE_SIGSETJMP
    siglongjmp(senv, 1);
    #else
    std::longjmp(env, 1);
    #endif
}

int main(int argc, char *argv[]) {
    struct sigaction sa;
    
    printSigMask(std::cout, "Signal mask at startup:");
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = handler;

    if(sigaction(SIGINT, &sa, NULL) == -1) {
        std::perror("sigaction");
        return EXIT_FAILURE;
    }

    #ifdef USE_SIGSETJMP
        std::cout << "\nCalling sigsetjmp()\n";
        if(sigsetjmp(senv, 1) == 0)
    #else
        std::cout << "\nCalling setjmp()\n";
        if(setjmp(env) == 0)
    #endif    
            canJump = 1;
        else
            printSigMask(std::cout, "After handler jump, signal mask is:" );
            
    for(;;)
        pause();
}

