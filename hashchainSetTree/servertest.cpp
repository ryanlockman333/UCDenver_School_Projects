/*
 * serverTest.cpp driver file
*/

// Defines
#define _XOPEN_SOURCE 500

// Headers
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cerrno>
#include <random>
#include <thread>
#include <ctime>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include "contact.h"
#include "hashchain.h" 
#include "socket.h"
#include "serversocket.h"

// Global Constants
const unsigned MAX_BUF = 512;

// Function Prototypes
std::string fgetDelim(FILE *&stream);
void fillFile(char *argv[]);
void fillHashChain(HashChain<Contact> &Chain, char *path);
void packet_dump(FILE *&stream, const unsigned char *buf, const unsigned int len);
void threadFuntion();   
void concurrentThread();
void outputIDs();

int main(int argc, char *argv[]) {
    // Declarations
    HashChain<Contact> Chain; 
	Contact Record, Grab; 

    // Check Arguments
    if(argc != 4 || strcmp(argv[1], "--help") == 0) {
        std::cout << "\nUsage: " << argv[0] << " [data file] [port] [inserts]"
                  << "\nCommands: --help\n\n";
        return 1;
    } 

    // Out IDs
    outputIDs();

    // Fill Data File and HashChain
    fillFile(argv);
    fillHashChain(Chain, argv[1]);
    std::cout << "\n\nCollisons: "    << Chain.getCollisions()
              << "\nIndex's Left: " << Chain.checkIndexLeft() << "\n\n"; 

    /*// Fork open file data
    pid_t pid = fork();
    if(pid == -1)
        perror("fork");
    else if(!pid) {
        std::cout <<"\nfork()ing a sniffer!\n\n";
        int ret = execl("/usr/bin/gnome-terminal", "gnome-terminal", "-e",
            "/root/Desktop/hashchainSetTree/sniff.out", NULL);
        if(ret == -1)
            perror("execl");
    }*/ 

    // Launch Packet Dumping Thread
    concurrentThread();

    // Fork open file data
    pid_t pid1 = fork();
    if(pid1 == -1)
        perror("fork1");
    else if(!pid1) {
        std::cout <<"\nfork()ing data file!\n\n";
        int ret1 = execl("/usr/bin/gvim", "gvim", "/root/Desktop/hashchainSetTree/data.dat", NULL);
        if(ret1 == -1)
            perror("execl1");
    }

    // Make Server Socket to Listen
    ServerSocket server(atoi(argv[2]));
    std::string packet;               

    // Fork clienttest.cpp
    pid_t pid2 = fork();
    if(pid2 == -1)
        perror("fork2");
    else if(pid2 == 0) {
        std::cout <<"\nfork()ing out client program!\n\n"; 
        int ret2 = execl("/usr/bin/gnome-terminal", "gnome-terminal", "-e",
            "/root/Desktop/hashchainSetTree/client.out localhost 44444", NULL);
        if(ret2 == -1)
            perror("execl2");
    }   

    // Wait For Process Termination
    int status;
    if(waitpid(pid2, &status, 0) == -1)
        perror("waitpid");
    else {
        if(WIFEXITED(status))
            std::cout << "\nNormal termination with exit status = " << WEXITSTATUS(status) << "\n";
        if(WIFSIGNALED(status))
            std::cout << "\nKilled by signal = "
                      << WTERMSIG(status) << (WCOREDUMP(status) ? " (dumped core)\n" : "\n");
        if(WIFSTOPPED(status))
            std::cout << "\nStopped by signal = " << WSTOPSIG(status) << "\n";
        if(WIFCONTINUED(status))
            std::cout << "\nContinued\n"; 
     } 

    // Loop Server
    while(1) {
        ServerSocket new_sock;   // conversation socket 
        server.accept(new_sock); // wait for connection acception
        
        // Wait for Client Pin
        std::cout << "\nServer: waiting for connections...\n"; 
        new_sock  >> packet;
        Record.setPin(packet); 
                
        // Validate Credentials
        if(Chain.find(atoi(packet.c_str()), Record, Grab)) {
            new_sock  << "0001"; // send access value
            new_sock  >> packet; // wait for client to continue
            new_sock  << Record.profileOut(); // send menu
            
            // Loop Client Access
            while(1) {
                packet = std::string(); // reset packet
                new_sock  >> packet;    // accept menu choice

                // Pocess Choice
                switch(std::atoi(packet.c_str())) {
                    case 1:
                        new_sock << Grab.getEmail();
                        break;
                    case 2:
                        new_sock << Grab.getPhone();
                        break;
                    case 3:
                        new_sock << Grab.getBirthday();
                        break;
                    case 4:
                        new_sock << "fuck";
                        break;
                    case 5:
                        new_sock << "fuck";
                        break;
                    case 6:
                        new_sock << "6";
                        break;
                    default:
                       new_sock << "Error, invalid option\n";
                }

                // Detect Client Closed
                if(packet == "6" || packet == std::string()) {
                    break;
                }
            }
        }
        else
            new_sock << "0000";
    }

    return 0;
}

// Function Implementations 
void fillFile(char *argv[]) {
    // Declarations
    std::stringstream ss;
    int fd = 0; 
    ssize_t numRead = 0;
    char buf[MAX_BUF] = {'\0'}; 

     // File to Write
    int openFlags = O_RDWR | O_CREAT | O_TRUNC;
    mode_t filePerms = S_IWUSR | S_IRUSR;; /* rw */ 

    if((fd = open(argv[1], openFlags, filePerms)) == -1) {
        perror("File: open error:");
        std::cout << "creating file...\n";
    }

    // Write File and Random Pin Creation
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(1, 9999);
    int count = 0;
    while(++count <= atoi(argv[3])) {
        ss << dist(mt) << ",FirstName,LastName,StreetAddress,City,State,Zip,Phone,Email,Birthday,\n";
        ss >> buf;
        size_t len = strlen(buf);
        
        if((numRead = write(fd, buf, len)) == -1) {
            perror("File: write error");
            exit(EXIT_FAILURE);
        }
        else if(numRead != (ssize_t)len) {
            std::cerr << "File: partial write error\n";
            exit(EXIT_FAILURE);   
        }
    }
    
    // Sync Dirty Buffers
    if((numRead = fsync(fd)) == -1)
        perror("File: fsync error");

    // Close File to Write
    if(close(fd) == -1)
        perror("File: close fd error");

}

void fillHashChain(HashChain<Contact> &Chain, char *path) {
    // Declarations
    Contact Record;
    std::string read;
    int c = 0;

    // File to Read
    FILE *stream = NULL;
    if(!(stream = fopen(path, "r"))) {
        perror("File: fopen error");
        exit(1);
    }

    // Read File and Fill Hash Chain
    while((c = fgetc(stream)) != EOF) {
        ungetc(c, stream); // discard EOD check

        read = fgetDelim(stream);
        Record.setPin(read);

        read = fgetDelim(stream);
        Record.setFirstName(read);
        read = fgetDelim(stream);
        Record.setLastName(read);
        read = fgetDelim(stream);

        Record.setStreet(read); 
        read = fgetDelim(stream);
        Record.setCity(read);
        read = fgetDelim(stream); 
        Record.setState(read);
        read = fgetDelim(stream);
        Record.setZip(read);

        read = fgetDelim(stream); 
        Record.setPhone(read);
        read = fgetDelim(stream);
        Record.setEmail(read);
        read = fgetDelim(stream); 
        Record.setBirthday(read);
    
        Chain.insertRecord(atoi(Record.getPin().c_str()), Record);
    }

    // Close File to Read
    if(fclose(stream)) {
        perror("File: fclose error");
        exit(1);
    }
}

std::string fgetDelim(FILE *&stream) {
    char buf[BUFSIZ], *s = NULL, d = ',';
    int c = 0;

    s = buf;
    while((c = fgetc(stream)) != EOF && (*s++ = c) != d);

    if(c == d)
        *--s = '\0';
    else if(c == EOF) {
        std::cerr << "EOF before delim";
        perror("Server: fgetc");
    }

    std::string str(buf); 
    return str;
}

void thread_function() {
    int received_length, sock_fd, i;
    u_char buf[5000];
    time_t t;

    time(&t); // pass to time function

    std::cout << "\nIn new thread..."
              << "\nStarting sniffer and packet dumping...\n";

    // Open File for Writing
    FILE *stream = NULL;
    if(!(stream = fopen("/root/Desktop/hashchainSetTree/log.dat", "ab"))) {
        perror("PacketDump File: open error");
        printf("Creating file log.txt .......");
    }  

    // Open Socket
    if((sock_fd = socket(PF_INET, SOCK_RAW, IPPROTO_TCP)) == -1) {
        perror("PacketDump Socket error");
        exit(1);
    }

    // Total Packet Reads
    std::cout << "\nTime Stamp: " << ctime(&t) << "\n";
    fprintf(stream,"\n\nTime Stamp: %s\n", ctime(&t));

    for(i = 0; i < 50; i++) {
        received_length = recv(sock_fd, buf, 4000, 0);
        printf("%d byte packet\n", received_length);
        packet_dump(stream, buf, received_length);
        printf("\n");
        fprintf(stream, "\n");
    }

    // Close File to Read
    if(fclose(stream))
        perror("PacketDump File: fclose error");

    std::cout << "\nLeaving new thread..."
              << "\n Ending sniffer and packet dumping...\n";   
}

void concurrentThread() {
    std::thread t(&thread_function); // new thread

    t.detach(); // detach thread

    if(t.joinable()) // check if re-joinable 
        t.join();
}

void packet_dump(FILE *&stream, const unsigned char *buf, const unsigned int len) {
    unsigned char c;
    std::size_t i = 0, j = 0;

    // Output Packets and Correct Display Format
    for(i = 0; i < len; ++i) {
        printf("%02x ", buf[i]);
        fprintf(stream, "%02x ", buf[i]);

        if((i % 16) == 15 || (i == len-1)) {
            for(j = 0; j < 15 - (i % 16); ++j) {
                printf("   ");
                fprintf(stream, "   ");
            }
        
            printf("| ");
            fprintf(stream, "| ");
            
            for(j = (i - (i % 16)); j <= i; ++j) {
                c = buf[j];
                if((c > 31) && (c < 127)) {
                    printf("%c", c);
                    fprintf(stream, "%c", c);
                }    
                else {
                    printf(".");
                    fprintf(stream, ".");
                }
            }
            
            printf("\n");
            fprintf(stream, "\n");
        }
    }
} 

void outputIDs() {
    // PID and PPID
    std::cout << "\nServer PID:  " << getpid()
              << "\nServer PPID: " << getppid();

    // Real User and Group ID
    std::cout << "\nReal User ID: "  << getuid()
              << "\nReal Group ID: " << getgid();

    // Effective User and Group ID
    std::cout << "\nEffective User ID: "  << geteuid()
              << "\nEffective Group ID: " << getegid();

    // Session ID
    pid_t sid = getsid(0);
    if(sid == -1)
        perror("getsid error"); // should never happen
    else
        std::cout << "\nSession ID: " << sid;

    // Process Group ID
    pid_t pgid = getpgid(0);
    if(pgid == -1)
        perror("getpgid"); // should never happen
    else
        std::cout << "\nProcess Group ID: " << pgid;   

}

