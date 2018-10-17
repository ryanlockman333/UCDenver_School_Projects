#include <cstdlib>
#include <cstdio>
#include <unistd.h>
#include <errno.h>

ssize_t read_line(int fd, void *buffer, const std::size_t n) {
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
        
        if(!numRead)             // EOF(0)
            if(!totRead)         // no bytes read(0)
                return 0; 
            else
                break; 

        if(totRead < n-1) {      // discard if > n-1 bytes
            *buf++ = ch;
            ++totRead;            
        }

        if(ch == '\n')
            break;
    }

    *buf = '\0';
    return totRead;
}

