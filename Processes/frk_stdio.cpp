/* ./frk_stdio > file (produces double out and reverse) Block-Buffered
 * ./frk_stdio        (priduces correct order and no doubles) Line-Buffered
 When standard output is directed to a terminal, it is line-buffered by default,
 with the result that the newline-terminated string written by printf() appears immediately.
 However, when standard output is directed to a file, it is block-buffered by default. Thus,
 in our example, the string written by printf() is still in the parent’s stdio buffer at the
 time of the fork(), and this string is duplicated in the child. When the parent and the
 child later call exit(), they both flush their copies of the stdio buffers, resulting in
 duplicate output.
 */

#include <cstdio>
#include <cstdlib>
#include <unistd.h>

int main() {
    std::printf("Hello world\n");
    write(STDOUT_FILENO, "Ciao\n", 5);
    
    if(fork() == -1) {
        std::perror("fork");
        return EXIT_FAILURE;
    }
    // both child and parent continue execution here
    
    exit(EXIT_SUCCESS); // same with return
}

