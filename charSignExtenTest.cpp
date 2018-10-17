#include <iostream>

int main() {
    // Wrong
    char c = 255;
    int  i = c; // sign extension fails, 2's comp of 255 is -1
    std::cout << '\n' << i;

    // Rite
    int j = (unsigned char)j; // doesn't fail
    std::cout << '\n' << j << "\n\n";
    return 0;
}

