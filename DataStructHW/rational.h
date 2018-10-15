// Header comments
// File: rational.h
// Definition of an adt that represents a rational number (ratio of two integers)
// NOTE: It would be useful to define a 'reduce' function for the class


#ifndef _rational
#define _rational
#include <iostream>

class rational
{
public:
    /***************** Constructors *******************/
    // Pre: None
    // Post: A default rational has been created using values (0,1);
    rational();

    // Pre: None
    // Post: A ratoinal has been crated with values (n,d);
    rational(int n, int d);

    /*************** Constant members ****************/
    int get_num() const { return num; }
    int get_den() const;
    void display() const;

    /**************** Modification members ***********/
    void set_num(int);
    void set_den(int);

    /**************** Operators *********************/
    rational operator + (const rational&) const;

    /**************** Friends ***********************/
    friend std::ostream& operator << (std::ostream&, const rational&);

    static int get_COUNT();

private:
    int num, den;
    static int COUNT;
};

rational operator * (const rational&, const rational&);

#endif
