#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <unistd.h>

int main(int argc, char **argv) {
    if(argc < 2 || !std::strcmp(argv[1], "-h")) {
        std::cerr << "\nUsage: " << argv[0] << " [pathname] [args]...\n\n";
        return EXIT_FAILURE;
    }

    const char *const a1 = argv[1] ? argv[1] : NULL,
               *const a2 = argv[2] ? argv[2] : NULL,
               *const a3 = argv[3] ? argv[3] : NULL,
               *const a4 = argv[4] ? argv[4] : NULL,
               *const a5 = argv[5] ? argv[5] : NULL,
               *const N  =  (const char *const)NULL;

    if(!a1) return EXIT_FAILURE;

    a2 ? a3 ? a4 ? a5 ? execlp(a1, a1, a2, a3, a4, a5, N)
                      : execlp(a1, a1, a2, a3, a4, N)
                      : execlp(a1, a1, a2, a3, N)
                      : execlp(a1, a1, a2, N)
                      : execlp(a1, a1, N);

    std::perror("execlp");
    return EXIT_FAILURE;
}

