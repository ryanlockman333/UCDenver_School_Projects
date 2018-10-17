#include <cstdio>
#include <cstring>
#include <csignal>
#include <cstdlib>
#include <string>
#include <iostream>
#include <sys/wait.h>

#define MAX_CMD_LEN 200

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

int main(int argc, char **argv) {
    // Loop
    for(;;) {
        std::cout << "\nCommand: ";
        std::fflush(stdout);
        
        // Get Text and Store in str
        char str[MAX_CMD_LEN] = {'\0'};
        if(!std::fgets(str, MAX_CMD_LEN, stdin))
            break;

        // Execute System Call
        int status = system(str);
        printf("system() returned: status=0x%04x (%d,%d)", (unsigned)status, status >> 8, status & 0xff);
        
        // Check Child Could Not Be Created Or Termination Status Not Read
        if(status == -1) {
            std::perror("system");
            return EXIT_FAILURE;
        }
        
        // Check Shell Could Not Be Execed In Child
        if(WIFEXITED(status) && WEXITSTATUS(status) == 127)
            std::cout << "\nProbably could not invoke shell, or shell exited with status 127(less likely)";
        else // success on system call status received, so print
            printWaitStatus(NULL, status);

        std::cout << std::endl;
    }

    return EXIT_SUCCESS;
}

