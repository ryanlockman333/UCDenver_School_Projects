#include <cstdlib>
#include <cstdio>
#include <unistd.h>

extern char **environ;

int main(int argc, char **argv) {
    for(int i = 0; i < argc; ++i)
        printf("argv[%d] = %s\n", i, argv[i]);
    for(char **ep = environ; *ep; ++ep)
        printf("environ: %s\n", *ep);
    return EXIT_SUCCESS;
}

