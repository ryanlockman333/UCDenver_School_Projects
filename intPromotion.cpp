#include <iostream>
int main() {
    int k = 0b1000001, l = 1000001;
    char e = k, f = l;
    std::cout << e << '\n' << f << "\n\n";

    int j  = 'A';
    char d = j;
    std::cout << j << '\n' << d << '\n';

    int *i  = (int*)"/poop";
    char *c = (char*)i;
    std::cout << "\nBase: " << *c << "\nWhole: " << c << '\n';
}
