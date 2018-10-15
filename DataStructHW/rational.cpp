// Header comments
// File: rational.cpp
// Implementation of a rational adt

#include "rational.h"

int rational::COUNT=0;

int rational::get_COUNT()
{
    return COUNT;
}

rational::rational():num(0),den(1)
{ ++COUNT; }

rational::rational(int n, int d):num(n), den(d)
{
    if(den==0) den=1;
    ++COUNT;
}

int rational::get_den() const
{
    return den;
}

void rational::display() const
{
    std::cout << '(' << num << ',' << den << ')';
}

void rational::set_num(int n)
{
    num=n;
}

void rational::set_den(int d)
{
    if(d!=0)
	den=d;
}

rational rational::operator + (const rational& r1) const
{
    int new_num = this->num*r1.den + this->den*r1.num;
    int new_den = this->den* r1.den;
    rational temp(new_num,new_den);
    return temp;
}

rational operator * (const rational& r1, const rational& r2)
{
    return rational(r1.get_num()*r2.get_num(), r1.get_den()*r2.get_den());
}

std::ostream& operator << (std::ostream& out, const rational& r)
{
    return out << '(' << r.num << ',' << r.den << ')';
}
