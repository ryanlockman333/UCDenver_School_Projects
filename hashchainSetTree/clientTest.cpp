/* 
clientTest.cpp driver file
*/

// Headers
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include "clientsocket.h"

// Function Prototypes
void out();

int main(int argc, char *argv[]) {
    // Declarations
	unsigned int pin = 0;
    std::string send, reply, menu;
    std::stringstream ss;      

    // Check Arguments
    if(argc != 3 || strcmp(argv[1], "--help") == 0) {
        std::cout << "\nUsage: " << argv[0] << " [localhost] [port]"
                  << "\nCommands: --help\n\n";
        return 1;
    }

    // Get PID and PPID
    std::cout << "\nServer PID:  " << getpid()
              << "\nServer PPID: " << getppid();

    // Get Real User and Group ID
    std::cout << "\nReal User ID: "  << getuid()
              << "\nReal Group ID: " << getgid();

    // Get Effective User and Group ID
    std::cout << "\nEffective User ID: "  << geteuid()
              << "\nEffective Group ID: " << getegid();

    // Get Session ID
    pid_t sid = getsid(0);
    if(sid == -1)
        perror("getsid error"); // should never happen
    else
        std::cout << "\nSession ID: " << getsid(0);   

    // Make Client Socket 
    ClientSocket client_socket(argv[1], atoi(argv[2]));

    // Prompt Pin
    std::cout << "\nEnter in your 4-digit pin: "; 
    std::cin  >> pin; 
    ss << pin;
    ss >> send;
                
    client_socket << send; // send pin
	client_socket >> reply;    
    std::cout << "\nClient: received:  " << reply; 
    
    if(reply == "0001") {
        std::cout << "\nAccess Granted\n";
        client_socket << "menu"; // request menu         
        client_socket >> menu;

        // loop connection
        while(reply != "6") {
            std::cout << menu;
            std::cout << "\nMake Choice: ";
            std::cin  >> send;

            client_socket << send; // send menu choice
    
            client_socket >> reply;
            std::cout << "\nClient: received: " << reply << "\n";
        }
    }
    else if(reply == "0000")
        std::cout << "\n\nAccess Denied\n";

    std::cout << "\nGood Bye\n";
    if(atexit(out))
        fprintf(stderr, "atexit() failed");
    return 0;
}

// Function Implementations
void out() { std::cout << "\natexit succeeded!\n"; }

