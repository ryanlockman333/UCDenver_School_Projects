/*
 * Iterative Sequence Number Server
 *
 ***************************************************************************************/

// Defines
#define _BSD_SOURCE // NI_MAXHOST, NI_MAXSERV from <netdb.h>

// Headers
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cerrno>
#include <cstring>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <signal.h>
#include <unistd.h>

// Global Constants
const unsigned INT_LEN = 30, BACKLOG = 50;

// Function Prototypes
static ssize_t read_line(int fd, void *buffer, const std::size_t n);

// Server Main
int main(int argc, char **argv) {
    // Check Args
    if(argc < 2 || argc > 3 || !std::strcmp(argv[1], "-h")) {
        std::cerr << "\nUsage : " << argv[0] << " [port] [init-seq-num]\n\n";
        return EXIT_FAILURE;
    }
    
    // Set Args
    const char* const PORT = argv[1];
    uint32_t seqNum = argc == 3 ? std::atoi(argv[2]) : 0;

    // Typedefs
    typedef struct sockaddr_storage sockaddr_storage;
    typedef struct addrinfo addrinfo;

    // Local Constants
    const unsigned ADDRSTRLEN = (NI_MAXHOST+NI_MAXSERV+10);

    // Declarations
    char reqLenStr[INT_LEN], // requested seq len
         seqNumStr[INT_LEN], // start of granted seq
         addrStr[ADDRSTRLEN],
         host[NI_MAXHOST], service[NI_MAXSERV];

    // Set Signal Disposition for SIGPIPE, syswrite on closed peer sock reports our EPIPE
    if(signal(SIGPIPE, SIG_IGN) == SIG_ERR) {
        std::perror("signal");
        return EXIT_FAILURE;
    }

    // Set Up Hints Struct for getaddrinfo
    addrinfo hints;   
    std::memset(&hints, 0, sizeof(addrinfo));
    hints.ai_protocol  = 0;                           // wild proto
    hints.ai_canonname = NULL;
    hints.ai_addr      = NULL;
    hints.ai_next      = NULL;
    hints.ai_socktype  = SOCK_STREAM;
    hints.ai_family    = AF_UNSPEC;                   // ip4 and ip6
    hints.ai_flags     = AI_PASSIVE | AI_NUMERICSERV; // wild ip and numeric service name
                                                                                                /* passiv and non null then passive is ignored(client)
                                                                                                 * passiv and null is wild and for bind and accept(server)
                                                                                                 * no passiv and null is loopback(server)
                                                                                                 * no pasiv and non nall is for connect/sendto/sendmsg(client)
                                                                                                 * */
    
    // Resolve Addr Structs List
    addrinfo *result = NULL;
    if(getaddrinfo(NULL, PORT, &hints, &result)) { // resolve through listen sock
        std::perror("getaddrinfo");
        return EXIT_FAILURE;
    }

    // Loop Through Addr Structs for Bindable Addr
    addrinfo *rp = result;
    int optval = 1, lfd = 0;
    for(; rp; rp = rp->ai_next) {
        // Create Socket
        if((lfd = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol)) == -1)
            std::perror("socket");
        
        // Set Socket Options
        if(setsockopt(lfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval))) {
            std::perror("setsockopt");
            return EXIT_FAILURE;
        }
       
        // Try to Bind Socket and Break on Success
        if(!bind(lfd, rp->ai_addr, rp->ai_addrlen))
            break;
        else
            std::perror("bind");

        // Close Socket, Unsuccessful
        if(close(lfd))
            std::perror("close");
    }

    // Check Unsuccessful Bind
    if(!rp) {
        std::cerr << "\nCould not bind address to socket\n";
        return EXIT_FAILURE;
    }

    // Make Listening Socket
    if(listen(lfd, BACKLOG)) {
        std::perror("listen");
        return EXIT_FAILURE;
    }

    // Deallocate Addr Structs List
    freeaddrinfo(result);

    // Loop Server
    for(;;) {
        // Addr Len
        socklen_t addrlen = sizeof(sockaddr_storage);

        // Accept Socket, Blocks(sleeps) if None Available
        sockaddr_storage claddr;
        int cfd = accept(lfd, (sockaddr*)&claddr, &addrlen);
        if(cfd == -1)
            std::perror("accept");

        // Get Name Info of Client
        if(getnameinfo((sockaddr*)&claddr, addrlen, host, NI_MAXHOST, service, NI_MAXSERV, 0))
            std::snprintf(addrStr, ADDRSTRLEN, "(?UNKNOWN?)");
        else
            std::snprintf(addrStr, ADDRSTRLEN, "(%s, %s)", host, service);           

        // Print Connection
        printf("Connection from %s\n", addrStr);
        
        // Read our Marshalled Data Encoded for Wire (client specifies seq num wanted)
        if(read_line(cfd, reqLenStr, INT_LEN) <= 0) {
            if(close(cfd))
                std::perror("close");
            continue; // skip failed read request
        }

        // Convert the Requested Seq Num to a Str
        int reqLen = std::atoi(reqLenStr);
 
        // Watch for Misbehaving Clients
        if(reqLen <= 0) {
            if(close(cfd))
                std::perror("close");
            continue; // skip bad request
        }

        // Send Curr Seq Val Back to Client, encoded as newln terminating str
        std::snprintf(seqNumStr, INT_LEN, "%d\n", seqNum);
        if(write(cfd, &seqNumStr, std::strlen(seqNumStr)) != (ssize_t)std::strlen(seqNumStr))
            std::perror("Partial/Failed write");

        // Update Seq Num
        seqNum += reqLen;

        // Close Socket
        if(close(cfd))
            std::perror("close");
    }

    // Shouldn't Get Here
    return EXIT_FAILURE;
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

