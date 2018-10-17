#include <iostream>

int main() {
    /*typedef void (a)(void*);
    a A;

    void (*)(void*);
    void (*)();
    
    typedef void* (*b)(void*);
    b B;*/

    std::cout << (* (int(*)())  ("\xc3"))() << '\n'; // correct way
    std::cout << (  (int(*)())& ("\xc3"))() << '\n'; // works
    std::cout << (  (int(*)())*&("\xc3"))() << '\n'; // works
    std::cout << (* (int(*)())*&("\xc3"))() << '\n'; // works
    std::cout << (**(int(*)())*&("\xc3"))() << '\n'; // works
    std::cout << (  (int(*)())  ("\xc3"))() << '\n'; // correct way

    std::cout << reinterpret_cast<int(*)()>("\xc3")() << '\n';
}

