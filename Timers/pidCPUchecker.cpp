#define _POSIX_C_SOURCE 199309
#define _XOPEN_SOURCE 600

#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <iostream>

int main(int argc, char **argv) {
    if(argc != 2) {
        std::cerr << "\nUsage: " << argv[0] << " [pid]\n\n";
        return EXIT_FAILURE;
    }

    clockid_t cid;
    if(clock_getcpuclockid(std::atol(argv[1]), &cid)) {
        std::perror("clock_getclockid");
        return EXIT_FAILURE;
    }
    
    timespec tspc;
    if(clock_gettime(cid, &tspc)) {
        std::perror("clock_gettime");
        return EXIT_FAILURE;
    }

    std::cout << "\nProcess: " << argv[1]
              << "\nCPU Time Consumed: ";
    printf("%ld\n\n", tspc.tv_sec);
    return EXIT_SUCCESS;
}

