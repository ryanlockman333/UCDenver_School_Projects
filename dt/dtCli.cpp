#include <iostream>
#include <string>
#include <cstdlib>
#include "clientsocket.h"

int main(int argc, char **argv) {
    ClientSocket cli_sock(argv[1], std::atoi(argv[2]));
    std::string packet;
    
    cli_sock  >> packet; // recieve
    std::cout << packet;

    return EXIT_SUCCESS;
}
