#include <iostream>
#include <limits>

int main() {
    std::cerr << "unsigned char: "
            << +std::numeric_limits<unsigned char>::min()
            << " to "
            << +std::numeric_limits<unsigned char>::max()
            << ", 0xFF = "
            << +static_cast<unsigned char>('\xFF')
            << std::endl
            << "  signed char: "
            << +std::numeric_limits<signed char>::min()
            << " to "
            << +std::numeric_limits<signed char>::max()
            << ", 0xFF = "
            << +static_cast<signed char>('\xFF')
            << std::endl
            << "  char: "
            << +std::numeric_limits<char>::min()
            << " to "
            << +std::numeric_limits<char>::max()
            << ", 0xFF = "
            << +static_cast<char>('\xFF')
            << std::endl;

    std::cout << '\n' << +'A' << " " << 'A' << '\n'; // unary + casts to an int implicitly
    
    int  i = '\xff';
    char c = '\xff';
    std::cout << +c << " " << std::hex << (int) c << std::dec << " " << (int)c << " "
              << (unsigned)c << " " << std::hex << (unsigned)c << std::dec << " "
              << +(char)i << " " << i << " " << (unsigned char)i << '\n';
}

