#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#define MAX_CMD_LEN 256

// Thread-safe, reentrant,async- signal-safe, doesnt modify globals or statics
int system(char *command) {
    pid_t cPid = fork();

    switch(cPid) {
    case -1: // Error
        return -1;
    case 0: // Child
        execl("/bin/sh", "sh", "-c", command, (char *)NULL);
        _exit(127); // failed exec
    default: // Parent
        int status = 0;
        if(waitpid(cPid, &status, 0) == -1)
            return -1;
        else
            return status;
    }
}

int main() {
    // Get Text and Store in str   
    std::cout << "\nCommand: ";
    std::fflush(stdout);
        
    char str[MAX_CMD_LEN] = {'\0'};
    if(!std::fgets(str, MAX_CMD_LEN, stdin)) {
        std::cerr << "\nfgets";
        return EXIT_FAILURE;
    }

    // Execute
    system(str);
    std::cout << std::endl;
    return EXIT_SUCCESS;
}

