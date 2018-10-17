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

    // Get Basename
    char *filename = std::strrchr(argv[1], '/');
    if(filename)
        ++filename;
    else
        filename = argv[1];

    // Set Environment
    const char *const envVec[] = {"GREET=salut", "BYE=adieu", NULL};

    // Execute
    execle(argv[1], filename, "hello world", (char*)NULL, envVec);
    std::perror("execle");
    return EXIT_FAILURE;
}

