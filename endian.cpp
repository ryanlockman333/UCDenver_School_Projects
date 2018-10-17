#include <cstdio>
int main() {
    #if __BYTE_ORDER == __LITTLE_ENDIAN
        printf("little endian\n");
    #else
        printf("big endian\n");
    #endif
}

