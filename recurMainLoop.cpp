#include <iostream>

static unsigned i = 10;
int main() {
    std::cout << i << '\n'; 
    if(i--) main();
}

