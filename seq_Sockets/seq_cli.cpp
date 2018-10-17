/*
 * Sequence Number Client
 *
 ********************************************************************************************/

// Headers
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cerrno>
#include <cstring>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

// Global Constants
const unsigned INT_LEN = 30;

// Function Prototypes
static ssize_t read_line(int fd, void *buffer, const std::size_t n);

// Client Main
int main(int argc, char **argv) {
    // Check Args
    if(argc < 3 || argc > 4 || !std::strcmp(argv[1], "-h")) {
        std::cerr << "\nUsage: " << argv[0] << " [host] [port] [seq-len]\n\n";
        return EXIT_FAILURE;
    }

    // Set Args
    const char *const HOST = argv[1], *const PORT = argv[2];

    // Typedefs
    typedef struct addrinfo addrinfo;

    // Declarations
    char seqNumStr[INT_LEN];

    // Set Up Hints Struct for getaddrinfo
    addrinfo hints;
    std::memset(&hints, 0, sizeof(addrinfo));
    hints.ai_canonname = NULL;
    hints.ai_addr      = NULL;
    hints.ai_next      = NULL;
    hints.ai_family    = AF_UNSPEC;      // ip4 and ip6
    hints.ai_socktype  = SOCK_STREAM;
    hints.ai_flags     = AI_NUMERICSERV; // numeric service name

    // Get Addr Structs List
    addrinfo *result = NULL;
    if(getaddrinfo(HOST, PORT, &hints, &result)) {
        std::perror("getaddrinfo");
        return EXIT_FAILURE;
    }

    // Loop Through Addr Structs for Connectable Addr
    addrinfo *rp = result;
    int cfd = 0;
    for(; rp; rp = rp->ai_next) {
        // Create Socket
        if((cfd = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol)) == -1)
            std::perror("socket");

        // Try to Connect Socket and Break on Success
        if(!connect(cfd, rp->ai_addr, rp->ai_addrlen))
            break;
        else
            std::perror("connect");

        // Close Socket, Unsuccessful
        if(close(cfd))
            std::perror("close");
    }

    // Check Unsuccessful Connect
    if(!rp) {
        std::cerr << "\nCould not connect address to socket\n";
        return EXIT_FAILURE;
    }

    // Deallocate Addr Structs List
    freeaddrinfo(result);

    // Send Client's Desired Sequence Len
    char *reqLenStr = argc == 4 ? argv[3] : (char*)"1";
    if(write(cfd, reqLenStr, std::strlen(reqLenStr)) != (ssize_t)std::strlen(reqLenStr)) {
        std::perror("Partial/Failed write (reqLenStr)");
        return EXIT_FAILURE;
    }

    // Finish Send As Newln Terminated Str
    if(write(cfd, "\n", 1) != 1) {
        std::perror("Partial/Failed write (newline)");
        return EXIT_FAILURE;
    }

    // Read our Marshalled Data Encoded for Wire (seq num returned back by server)
    ssize_t numRead = read_line(cfd, seqNumStr, INT_LEN);
    if(numRead == -1) {
        std::cerr << "\nreadLine";
        return EXIT_FAILURE;
    }

    // Check EOF(0)
    if(!numRead)
        std::cerr << "\nUnexpected EOF from server";
    
    // Print Seq Num
    printf("Sequence number: %s", seqNumStr); // includes \n

    return EXIT_SUCCESS; // closes cfd
}

// Function Implementations
ssize_t read_line(int fd, void *buffer, const std::size_t n) { // Read Marshalled Data+Codebase
    // Check Params    
    if(n <= 0 || !buffer) {
        errno = EINVAL;
        return -1;
    }

    // Declarations
    ssize_t numRead = 0;
    std::size_t totRead = 0;
    char ch = 0;
    char *buf = (char*)buffer;   // no ptr arithmetic on void*

    // Loop Read
    for(;;) {
        if((numRead = read(fd, &ch, 1)) == -1 && errno != EINTR) { // contiunue on iterupt
            std::perror("read");
            return -1;
        }
        
        // Check EOF(0)
        if(!numRead) {
            if(!totRead) // total bytes read(0)
                return 0; 
            else
                break;
        }

        // Discard if > n-1 Bytes
        if(totRead < n-1) {
            *buf++ = ch;
            ++totRead;            
        }

        // Break on Newln
        if(ch == '\n')
            break;
    }

    // NULL Terminate
    *buf = '\0';
    return totRead;
}

