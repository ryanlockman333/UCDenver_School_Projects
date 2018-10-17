#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cerrno>
#include <cstdio>
#include <signal.h>

int main(int argc, char *argv[]) {
    if(argc != 3 || std::strcmp(argv[1], "--help") == 0) {
        std::cerr << '\n' << argv[0] << " [PID] [SIGNAL NUM]\n\n";
        return EXIT_FAILURE;
    }
    const int SIG = std::atol(argv[2]), PID = std::atoi(argv[1]);

    int s = kill(PID, SIG);
    if(s == -1) {
        if(errno == EPERM)
            std::cout << "\nProcess exists, but we don't have permission to send it a signal.\n\n";
        else if(errno == ESRCH)
            std::cout << "\nProcess does not exist.\n\n";
        else
            std::perror("kill");

        return EXIT_FAILURE;       
    }
    
    if(s == 0)
        std::cout << "\nProcess exists and we can send it a signal.\n\n";

    return EXIT_SUCCESS;
}

