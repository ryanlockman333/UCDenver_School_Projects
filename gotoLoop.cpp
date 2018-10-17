#include <iostream>

int main() {
    int i = 10;
    loop:
        std::cout << i << '\n';
        if(--i) goto loop;
}

