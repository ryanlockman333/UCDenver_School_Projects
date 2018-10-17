// Feature Test Macros
#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

// Headers
#include <cstdlib>
#include <iostream>
#include <csignal>
#include <cerrno>
#include <cstring>
#include <cstdio>
#include <sys/wait.h>
#include <fcntl.h>
#include <sched.h>
#include <unistd.h>

// Defines
#ifndef CHILD_SIG
#define CHILD_SIG SIGUSR1 // generated termination signal
#endif

// Child Starts Here
static int child_func(void *arg) {
    if(close( *((int*)arg) )) {
        std::perror("close");
        return -1;
    }
    return 0;
}
// Child Ends Here

// Main
int main(int argc, char **argv) {
    // Local Constants
    const unsigned STACK_SIZE = 65536;

    // Open Garbage dev/null FD
    int fd = open("/dev/null", O_RDWR);
    if(fd == -1) {
        std::perror("open");
        return EXIT_FAILURE;
    }

    // Share FD if argc>1
    int flags = argc > 1 ? CLONE_FILES : 0;

    // Set Up Child Stack
    char *stack = (char*)std::malloc(STACK_SIZE);
    if(!stack) {
        std::perror("malloc");
        return EXIT_FAILURE;
    }

    // Set Up Top of Stack(assume downward growth)
    char *stackTop = stack + STACK_SIZE;

    // Ignore CHILD_SIG if != 0 and != SIGCHLD Incase a Signal Terminates Process
    // Directley Ignoring SIGCHLD Prevents Parent From Waiting on Status
    if(CHILD_SIG && CHILD_SIG != SIGCHLD)
        if(std::signal(CHILD_SIG, SIG_IGN) == SIG_ERR) {
            std::perror("signal");
            return EXIT_FAILURE;
        }

    // Clone a Child
    if(clone(child_func, stackTop, flags | CHILD_SIG, (void*)&fd) == -1) {
        std::perror("clone");
        return EXIT_FAILURE;
    }

    // Parent Wait for Child Termination
    if(waitpid(-1, NULL, CHILD_SIG != SIGCHLD ? __WCLONE : 0) == -1) {
        std::perror("waitpid");
        return EXIT_FAILURE;
    }
    std::cout << "\nChild: Terminated";

    // Read From FD and Evaluate
    int nread = write(fd, "x", 1);
    if(nread == -1 && errno == EBADF)
        std::cout << "\nFile Descriptor " << fd << ": Closed"; // childs close effected parent
    else if(nread == -1)
        std::cout << "\nwrite(): File Descriptor " << fd << ": Failed: Errno: " << std::strerror(errno); // error
    else
        std::cout << "\nwrite(): File Descriptor " << fd << ": Succeeded"; // success

    std::cout << "\n\n";
    return EXIT_SUCCESS;
}

