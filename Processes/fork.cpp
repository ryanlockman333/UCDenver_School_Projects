// Headers
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>

// Main
int main() {
// Disable stdout Buffering
    setbuf(stdout, NULL);
   
// Make a Temp File and Print Offset
    char temp[] = "/tmp/testXXXXXX";
    int fd = mkstemp(temp);
    if(fd == -1) {
        std::perror("mkstemp");
        return EXIT_FAILURE;
    }
    std::cout << "\nFile offset before fork():      " << lseek(fd, 0, SEEK_CUR);
    
// Get Status Flags and Print
    int flags = fcntl(fd, F_GETFL);
    if(flags == -1) {
        std::perror("fcntl - F_GETFL");
        return EXIT_FAILURE;
    }
    std::cout << "\nO_APPEND flag before fork() is: " << (flags & O_APPEND ? "on" : "off");

// Fork Program Flow
    switch(fork()) {
    // Error
    case -1:
        std::perror("fork");
        return EXIT_FAILURE;
    // Child
    case 0:
        // Change Offset and Flags
        if(lseek(fd, 1000, SEEK_SET) == -1) {
            std::perror("lseek");
            return EXIT_FAILURE;
        }
            
        // Get Current Flags
        if((flags = fcntl(fd, F_GETFL)) == -1) {
            std::perror("fcntl - F_GETFL");
            return EXIT_FAILURE;
        }
            
        // Turn On Append
        //flags |= O_APPEND;
        if(fcntl(fd, F_SETFL, (flags |= O_APPEND)) == -1) {
            std::perror("fcntl - F_SETFL");
            return EXIT_FAILURE;
        }
            
        // Soft Exit Child
        _exit(EXIT_SUCCESS);
    // Parent
    default:
        // Wait for Child Exit
        if(wait(NULL) == -1) {
            std::perror("wait");
            return EXIT_FAILURE;
        }
        std::cout << "\n\nChild has exited"
                  << "\nFile offset in parent:          " << lseek(fd, 0, SEEK_CUR);

        // Get Current Flags and Print
        if((flags = fcntl(fd, F_GETFL)) == -1) {
            std::perror("fcntl - F_GETFL");
            return EXIT_FAILURE;
        }
        std::cout << "\nO_APPEND flag in parent is:     " << (flags & O_APPEND ? "on" : "off")
                  << "\n\n";
        
        // Hard Exit Parent
        return EXIT_SUCCESS;
    }

// End    
    return EXIT_FAILURE; // shouldnt get here
}

