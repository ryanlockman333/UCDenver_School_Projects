#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <unistd.h>
    
int main(int argc, char **argv) {
    char *env = getenv("USER");
    if(env)
        std::printf("Initial value of USER: %s\n", getenv("USER")); // cant use std::cout
    else
        return EXIT_FAILURE;

    if(putenv((char*)"USER=britta")) {
        std::perror("putenv");
        return EXIT_FAILURE;
    }

    execl("/usr/bin/printenv", "printenv", "USER", "SHELL", (char*)NULL);
    std::perror("execl");
    return EXIT_FAILURE;
}

