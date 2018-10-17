/* 
 *
 * */

// Headers
#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <strings.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>

const unsigned MAXLINE = 4096;

int main(int argc, char *argv[]) {
    int sockfd = 0, ret = 0;
    char line[MAXLINE+1];
    struct sockaddr_in servaddr;

    // Check Args
    if(argc != 2) {
        std::cerr << "\nUsage: " << argv[0] << " [IP Address]\n";
        return EXIT_FAILURE;
    }

    // Make Socket
    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        std::perror("socket");
        return EXIT_FAILURE;
    }

    // Zero Out
    bzero(&servaddr, sizeof(servaddr));

    // Set Address Family
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(13); // day-time server

    if(inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        std::perror("inet_pton");
        return EXIT_FAILURE;
    }

    // Make Connection
    if(connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) {
        std::perror("connect");
        return EXIT_FAILURE;
    }

    // Recieve
    while((ret = read(sockfd, line, MAXLINE)) > 0) {
        line[ret] = 0; // null terminate
        if(std::fputs(line, stdout) == EOF) {
            std::perror("fputs");
            return EXIT_FAILURE;
        }
    }

    // Check Read Error
    if(ret < 0) {
        perror("read");
        return EXIT_FAILURE;
    }

    return 0;
}

