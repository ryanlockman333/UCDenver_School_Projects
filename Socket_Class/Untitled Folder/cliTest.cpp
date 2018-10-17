#include <iostream>
#include <cstdlib>
#include "clientsocket.h"

int main(int argc, char **argv) {
    try{
        ClientSocket cli(argv[1], std::atoi(argv[2]));
        std::string str;

        try {
            cli << "Hello World";
        }
        catch(int) {
            return 1;
        }

        try {
            cli >> str; // receive
        }
        catch(int) {
            return 1;
        }
        std::cout << "\nReceived: " << str << '\n';
    }
    catch(int) {
        return 1;
    }

    return 0;
}

