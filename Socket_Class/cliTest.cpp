#include <iostream>
#include <cstdlib>
#include "clientsocket.h"

int main(int argc, char **argv) {
    ClientSocket cli(argv[2], std::atoi(argv[2]));

    std::string str;
    cli << "Hello World";
    cli >> str;
    std::cout << "\nReceived: " << str << '\n';
    return 0;
}

