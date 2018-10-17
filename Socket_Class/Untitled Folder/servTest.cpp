// Headers
#include <string>
#include <cstdlib>
#include <cstdio>
#include <csignal>
#include <sys/wait.h>
#include "serversocket.h"

// Function Prototypes
static void grimreaper(int sig);
static std::string strToUpper(const std::string str);

// Main Server
int main(int argc, char **argv) {
// Set Up Our Grim Reaper
    struct sigaction sa;
    sa.sa_handler = grimreaper;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART;

    if(sigaction(SIGCHLD, &sa, NULL)) {
        std::perror("sigaction");
        return EXIT_FAILURE;
    }

// Loop Server
    ServerSocket serv(argv[1]); // listen socket
    for(;;)
        try {
            ServerSocket conn_sock; // conn socket
            serv.accept(conn_sock);

            std::string str;
            conn_sock >> str;
            conn_sock << strToUpper(str); // echo
        }
        catch(int) {
            return EXIT_FAILURE;
        }

// Shouldnt Get Here
    return EXIT_FAILURE;
}

// Function Implementations
void grimreaper(int sig) {
    while(waitpid(-1, NULL, WNOHANG) > 0); // dont block, if kids are not yet dead
}

std::string strToUpper(const std::string str) {
	std::string ans = str;

	// Process strToUpper
	for(size_t i = 0; i < str.length(); i++)
		ans[i] = std::toupper((unsigned char)str[i]);

	return ans;
}

