#ifndef _GNU_SOURCE /* Get strsignal() declaration from <string.h> */
#define _GNU_SOURCE
#endif

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <sys/wait.h>
#include <unistd.h>

/* std::cout is non-reentrant, so this function is alos non-reentrant,
 * should not be used in a signal handler (non-async-signal-safe) */
void printWaitStatus(const std::string *const msg, const int status) {
    // Print Optional Message
    if(msg)
        std::cout << msg;

    // Child Exited Normally, Probe Exit Status(lower 8 bts(0-255))
    if(WIFEXITED(status))
        std::cout << "Child Exited: Status: " << WEXITSTATUS(status);
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
    // End Line
    std::cout << std::endl;
}

// Main
int main(int argc, char **argv) {
// Check Args
    if((argc > 1 && !std::strcmp(argv[1], "-h")) || argc > 2) {
        std::cerr << "\nUsage: " << argv[0] << " [exit-status]\n\n";
        return EXIT_FAILURE;
    }

// Fork Program Flow
    switch(fork()) {
    // Error
    case -1:
        std::perror("fork");
        return EXIT_FAILURE;
    // Child
    case 0:
        // Print Info
        std::cout << "\nChild Started: PID: " << getpid();
        
        // Check Supplied Exit Signal Status Numebr and Pause
        if(argc > 1)
            exit(std::atoi(argv[1]));
        else for(;;)
            pause(); // wait on signal

        // No Arg Return Test Failure(usually 1) Exit Signal 
        return EXIT_FAILURE;
    // Parent
    default:
        // Wait for Dead Children
        for(int status = 0; !WIFEXITED(status) || !WIFSIGNALED(status); printWaitStatus(NULL, status)) {
            pid_t cPid = waitpid(-1, &status, WUNTRACED 
                                 #ifdef WCONTINUED /* > Linux 2.6.10 */
                                 | WCONTINUED
                                 #endif
                                );
            if(cPid == -1) {
                std::perror("waitpid");
                return EXIT_FAILURE;
            }
            
            // Print Child's Obituary
            std::cout << "\nwaitpid() Returned: PID: " << cPid << " Status: 0x" << std::hex
                      << status << std::dec << " (" << (status >> 8) << ", " << (status & 0xff) << ")\n";
            printf("waitpid() returned: PID=%ld; status=0x%04x (%d,%d)\n",
                    (long)cPid, (unsigned int)status, status >> 8, status & 0xff);
        }
        return EXIT_SUCCESS;
    }
}

