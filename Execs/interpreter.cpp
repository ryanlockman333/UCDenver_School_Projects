#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <unistd.h>

int main(int argc, char **argv) {
// Check Args
    if(argc < 2 || !std::strcmp(argv[1], "-h")) {
        std::cerr << "\nUsage: " << argv[0] << " [pathname] [args]...\n\n";
        return EXIT_FAILURE;
    }

// Set Args
    char *a1 = std::strrchr(argv[1], '/');
    if(a1)
        ++a1;
    else
        a1 = argv[1];


    const char *const a2 = argv[2] ? argv[2] : NULL,
               *const a3 = argv[3] ? argv[3] : NULL,
               *const a4 = argv[4] ? argv[4] : NULL,
               *const a5 = argv[5] ? argv[5] : NULL,
               *const N  =  (const char *const)NULL;

    if(!a1) return EXIT_FAILURE;

// Set Up Environment
    char* envVec[] = {(char*)"GREET=salut", (char*)"BYE=adieu", NULL};

// Execute
    a2 ? a3 ? a4 ? a5 ? execle(a1, a1, a2, a3, a4, a5, N, envVec)
                      : execle(a1, a1, a2, a3, a4, N, envVec)
                      : execle(a1, a1, a2, a3, N, envVec)
                      : execle(a1, a1, a2, N, envVec)
                      : execle(a1, a1, N, envVec);

    // Error
    std::perror("execve");
    return EXIT_FAILURE;
}

