#include <iostream>

int main() {
    std::cout << ((int(*)())("\xc3 <- This returns the value of the EAX register"))() << '\n';
}

