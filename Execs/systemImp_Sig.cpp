// Headers
#include <cstdlib>
#include <limits>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <csignal>
#include <cerrno>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <linux/limits.h>

// Global Constants
const unsigned MAX_CMD_LEN = 200;

// Function Prototypes/Implementations
/* 
   Modifies signal dispositions which are process-wide, so non-thread-safe or non-reentrant-safe
   non-async-signal-safe
   Checks if sh is non-standard shell.
   Dont use in set-uid/set-gid programs because environment variables can breach secutiry.
   Shell may return error code 127, which can be indistinguishable from child execl.
   No signal dispositon manipulation error checking(to accuratley return fork and execl error).
   Returns error code 127 if shell execution failed, sets errno.
   Returns error code -1 if child couldnt be forked or waited upon, sets errno.
   Returns child status on success.   
   If command is NULL, return 0(false) if shell is not available, otherwise non-zero(true).
*/
int system(const char *const command) {
    // Recursivley Check Shell Availablility
    if(!command)
        return system(":") == 0;                  // : shell command to check return status

    // Set Mask to Block Child Signal in Parent incase Child Exits Early
    sigset_t blockMask, origMask;
    sigemptyset(&blockMask);
    sigaddset(&blockMask, SIGCHLD);
    sigprocmask(SIG_BLOCK, &blockMask, &origMask); // no error check

    // Set Handler to Ignore Interrupt and Quit Signals
    struct sigaction saIgnore, saOrigInt, saOrigQuit;
    saIgnore.sa_handler = SIG_IGN;
    saIgnore.sa_flags   = 0;
    sigemptyset(&saIgnore.sa_mask);                // no error check
    sigaction(SIGINT, &saIgnore, &saOrigInt);      // no error check
    sigaction(SIGQUIT, &saIgnore, &saOrigQuit);    // no error check

    // Fork Program Flow
    int status = 0;                                // child status
    pid_t cPid = fork();
    switch(cPid) {
    case -1: // Error
        status = -1;                               // fork error
        break;
    case 0:  // Child
        // Set Child Handler to Default Disposition for Interrupt and Quit Signals
        // Only if Child Didnt Inherit Ingored Interrupt and Quit Signals from Parent
        struct sigaction saDefault;
        saDefault.sa_handler = SIG_DFL;
        saDefault.sa_flags   = 0;
        sigemptyset(&saDefault.sa_mask);

        if(saOrigInt.sa_handler != SIG_IGN)
            sigaction(SIGINT, &saDefault, NULL);   // no error check
        if(saOrigQuit.sa_handler != SIG_IGN)
            sigaction(SIGQUIT, &saDefault, NULL);  // no error check
        
        // Restore Original Mask and Execute Shell Command
        sigprocmask(SIG_SETMASK, &origMask, NULL); // no error check
        //execl("/bin/sh", "sh", "-c", command, (char*)NULL);
      
        // Check if sh is Standard POSIX Shell
        char path[PATH_MAX];
        if(!confstr(_CS_PATH, path, PATH_MAX))     // get configuration variable
            _exit(127);                            // shell error
        if(setenv("PATH", path, 1))                // assign list(path) to PATH
            _exit(127);                            // shell error
        
        // Execute Command
        execlp("sh", "sh", "-c", command, (char*)NULL);
        _exit(127);                                // shell error
    default: // Parent
        // Wait for Child and Restart if Interupted by Signal Handler
        while(waitpid(cPid, &status, 0) == -1) {
            if(errno != EINTR) {
                status = -1;                       // wait error
                break;
            }
        }
        break;
    }

    // Unblock Child Signal and Reset Interrupt and Quit Signal Dispositions
    int savedErrno = errno;                        // save errno incase chaged
    sigprocmask(SIG_SETMASK, &origMask, NULL);     // no error check
    sigaction(SIGINT, &saOrigInt, NULL);           // no error check
    sigaction(SIGQUIT, &saOrigQuit, NULL);         // no error check
    errno = savedErrno;                            // restore

    // Successful System Call
    return status;
}

/* 
   std::cout is non-reentrant, so this function is also non-reentrant.
   Should not be used in a signal handler(non-async-signal-safe).
*/
static void printWaitStatus(const std::string *const msg, const int status) {
    // Print Optional Message
    if(msg) std::cout << msg;

    // Child Exited Normally, Probe Exit Status(lower 8 byts(0-255))
    if(WIFEXITED(status))
        std::cout << "\nChild Exited: Status: " << WEXITSTATUS(status);
    // Child Killed By A Signal, Probe Exit Signal Number And Core Dump
    else if(WIFSIGNALED(status)) {
        std::cout << "\nChild Killed: Signal: " << WTERMSIG(status)
                  << " (" << strsignal(WTERMSIG(status)) << ')';
        
        /* SUSv3 non-specified, may be absent on some systems */
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
    /* SUSv3 specified, older Linux versions plus some UNIX implementations dont */   
    #ifdef WIFCONTINUED 
    else if(WIFCONTINUED(status))
        std::cout << "\nChild Continued: Signal: (" << strsignal(SIGCONT) << ')';
    #endif
    // Shouldn't Get Here
    else
        std::cout << "\nChild Is Missing? (status: " << (unsigned)status << ')';
}

void flush_stream() {
    std::cin.clear(); // reset flags
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard stream input
}

// Main
int main() {
    // Loop User Input
    for(;;) {
        // Clear Screen Through ANSII Escape Sequences
        if((write(1,"\E[H\E[2J",7)) == -1)
            std::perror("write - clear screen");

        // Check if Shell is Available
        if(system(NULL))
            std::cout << "\nShell is available.\n";
        else {
            std::cout << "\nShell is not available.\n";
            return EXIT_FAILURE;
        }

        // Get Text and Store in str       
        std::cout << "\nCommand: ";
        std::fflush(stdout); // flush dirty data

        char str[MAX_CMD_LEN] = {'\0'};
        if(!std::fgets(str, MAX_CMD_LEN, stdin))
            break;

        // Execute System Call
        int status = system(str);
        std::cout << "\nsystem(): Returned Status: 0x" << std::hex << (unsigned)status << std::dec
                  << " (" << (status >> 8) // exit status consists of the LSB 8 bits(byte), so we rightshift 8 right
                  << "," << (status & 0xff) << ")"; // reason(signal) exited is stored in the next LSB 8 bits(byte), so we bitwise AND 255(0xff); can divide(status / 256) for same result if exited normally
                                           // should ALWAYS use WEXITSTATUS because status can be system dependant

        // Check Child Could Not Be Created Or Termination Status Not Read
        if(status == -1) {
            std::perror("system");
            return EXIT_FAILURE;
        }
        
        // Check if Shell Could Not Be Execed In Child
        if(WIFEXITED(status) && WEXITSTATUS(status) == 127)
            std::cerr << "\nShell: Invocation Error(Probably)"
                      << ", or Shell: Exited Status: 127(Less Likely)";

        else // success on system call, child status received so print
            printWaitStatus(NULL, status);

        // Pause for User, Then Hard Flush
        std::cout << std::endl;
        flush_stream();
    }

    return EXIT_FAILURE; // shouldnt get here
}

