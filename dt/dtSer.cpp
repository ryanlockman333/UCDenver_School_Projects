#include <ctime>
#include <cstdlib>
#include "serversocket.h"

static const unsigned MAXLINE = 4096;

int main(int argc, char **argv) {
    ServerSocket serv_sock(std::atoi(argv[1]));

    for(;;) {
        ServerSocket conn_sock; // Connection Socket

        std::cout << "\nServer waiting for connection.....\n";       
        serv_sock.accept(conn_sock);

        conn_sock.printConn();

        std::time_t ticks = std::time(NULL);
        conn_sock << std::ctime(&ticks);
    }

    return EXIT_SUCCESS;
}
