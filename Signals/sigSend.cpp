#include <iostream>
#include <cstring>
#include <cstdlib>
#include <signal.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if(argc < 4 || std::strcmp(argv[1], "--help") == 0) {
        std::cerr << '\n' << argv[0] << " [pid] [num-sigs] [sig-num] [sig-num-2]\n\n";
        return EXIT_FAILURE;
    }

    pid_t PID       = std::atol(argv[1]);
    unsigned NUMSIG = std::atoi(argv[2]);
    int SIG         = std::atoi(argv[3]);

    std::cout << '\n' << argv[0] << ": sending signal " << SIG
              << " to process " << PID << ", " << NUMSIG << " times.\n";

    for(unsigned i = 0; i < NUMSIG; ++i)
        if(kill(PID, SIG) == -1) {
            std::cerr << "\nkill1 error\n";
            return EXIT_FAILURE;
        }

    // If a fourth command-line argument was specified, send that signal
    if(argc > 4)
        if(kill(PID, std::atol(argv[4])) == -1) {
            std::cerr << "\nkill2 error\n";
            return EXIT_FAILURE;
        }

    std::cout << "\nExiting " << argv[0] << std::endl;
    return EXIT_SUCCESS;
}

