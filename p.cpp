#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <unistd.h>
#include <signal.h>

main(int argc, char **argv) {
    if(argc != 2) {
        printf("use: %s <hostname>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int pid = fork();
    if(pid == -1)
        std::perror("fork1");
    else if(!pid) {
        int ret = execl("/bin/ping", "ping", argv[1], NULL);    
        if(ret == -1)
            std::perror("execl");
    }
    
    sleep(1); // catch up
    while(!kill(pid, SIGALRM));
}

