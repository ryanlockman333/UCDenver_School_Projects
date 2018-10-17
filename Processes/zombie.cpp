#include <csignal>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <libgen.h> /* For basename() declaration */
#include <unistd.h>

#define CMD_SIZE 256

int main(int argc, char **argv) {
    // Disable Userspace Buffering
    setbuf(stdout, NULL);

    std::cout << "\nParent PID: " << getpid();

    pid_t cPid = fork();
    switch(cPid) {
    // Error
    case -1:
        std::perror("fork");
        return EXIT_FAILURE;
    // Child
    case 0:
        std::cout << "\nChild PID:  " << getpid() << ": Exiting\n";
        _exit(EXIT_SUCCESS);
    // Parent
    default:
        // Give Child Exit Chance
        if(sleep(3))
            std::perror("sleep");

        // Fill Command
        char cmd[CMD_SIZE];
        std::snprintf(cmd, CMD_SIZE, "ps | grep %s", basename(argv[0])); // null terminates
        
        // View Zombie
        system(cmd);

        // Send Sure Kill
        if(kill(cPid, SIGKILL))
            std::perror("kill");

        // Give Child Signal Reaction Chance
        if(sleep(3))
            std::perror("sleep");

        // Print and View Zombie
        std::cout << "\nAfter sending SIGKILL to zombie, PID: " << cPid << "\n";
        system(cmd);
        std::cout << "\n\n";
        return EXIT_SUCCESS;
    }
}

