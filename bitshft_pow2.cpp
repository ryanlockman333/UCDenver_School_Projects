#include <cstdlib>
#include <iostream>

/*
 * For signed numbers, right shift operator is implementation defined,
 * no garenteed 0 padding.
*/

// e.g. 7*(2^2)=28, 5*(2^2)=20, 1*(2^2)=4, 5*(2^3)=40
int mult_by_pow_2(const int number, const int power) {
    return number << power;
}

// e.g. 7/(2^2)=1.75=1, 5/(2^2)=1.25=1, 12/(2^2)=3
int div_by_pow_2(const int number, const int power) {
    return number >> power;
}

int main(int argc, char **argv) {
    std::cout << "\nLeft  Shift Answer: "
              << mult_by_pow_2(std::atoi(argv[1]), std::atoi(argv[2]))
              << "\nRight Shift Answer: "
              << div_by_pow_2(std::atoi(argv[1]), std::atoi(argv[2]))
              << "\n\n";
    return EXIT_SUCCESS;
}

