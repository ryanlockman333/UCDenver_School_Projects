/********************************************************************************************************
 * Ryan Lockman                                                                                         *
 * bin_coeff.h                                                                                          *
 * Description: bin_coeff class prototypes.                                                             *
 * 5/7/14                                                                                               *
 ********************************************************************************************************/

// Macro
#ifndef BIN_COEFF_H
#define BIN_COEFF_H

// Headers
#include <tuple>
#include <utility>
#include <vector>
#include <iostream>

// Binomial Coefficient Variadic Template Class
template <typename... Ts> class Bin_Coeff {
public:
// Typedefs
    typedef std::tuple<Ts...> Tuple; // tuple(c++11)
    typedef std::vector<unsigned long> Vec; 

// Constructors
    Bin_Coeff() : data(), bin() {} // default
    // Post: Initializes data mambers

// Modification Members
    void pascal(unsigned long n);
    // Pre:  Overflow results if n > 22, could be lower on some systems/architectures
    // Post: Computes the binomial theorem via pascal's triangle and fills bionomial with it
    void clear() { bin.clear(); }
    // Post: Clears and resets bionomial

// Constant Members
    auto size()->typename std::tuple_size<Tuple> const { return std::tuple_size<decltype(data)>::value; }
    // Post: Returns size of the bionomial
    bool empty() const { return bin.empty(); }
    // Post: Returns true if binomial is empty, false otherwise
    void print() const;
    // Post: Prints the bionomial to stdout

private:
// Data Members
    Tuple data;
    Vec   bin;

// Helper Members
    inline unsigned long fact(unsigned long n);
    inline unsigned long binomial(unsigned long n, unsigned long k);
};

#include "bin_coeff.tem"
#endif

