#include <iostream>

int ii = 333;

void foo(int* const& p) {
    *p = 444;
    //p = &ii;
}

int main() {
    int i  = 3;
    int *p = &i;

    std::cout << "\nP Before: " << *p << std::endl;
    foo(p);
    std::cout << "\nP After: " << *p << std::endl;
    std::cout << "\nI After: " << i << std::endl;   
}
