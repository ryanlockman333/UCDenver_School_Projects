#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <unistd.h>

int main(int argc, char **argv) {
    // Check Args
    if(argc != 2 || !std::strcmp(argv[1], "-h")) {
        std::cerr << "\nUsage: " << argv[0] << " [pathname]\n\n";
        return EXIT_FAILURE;
    }

    // Set Up Args
    char *argVec[] = {std::strrchr(argv[1], '/'), (char*)"hello world", (char*)"goodbye", NULL};
    if(argVec[0])
        ++argVec[0];
    else
        argVec[0] = argv[1];

    // Set Up Environment
    char* envVec[] = {(char*)"GREET=salut", (char*)"BYE=adieu", NULL};

    // Execute
    execve(argv[1], argVec, envVec);
    
    // Error
    std::perror("execve");
    return EXIT_FAILURE;
}

