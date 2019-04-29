#ifndef _FRACTION_H_
#define _FRACTION_H_
#include <iostream>
#include "InvalidArgumentException.h"
class Fraction
{
    friend std::ostream &operator<<(std::ostream &, const Fraction &);
    friend Fraction operator+(const Fraction&, const Fraction &);
    friend Fraction operator-(const Fraction&, const Fraction &);
    friend Fraction operator*(const Fraction&, const Fraction &);
    friend Fraction operator/(const Fraction&, const Fraction &)throw (InvalidArgumentException);
    friend bool operator<(const Fraction&, const Fraction &);
    friend bool operator>(const Fraction&, const Fraction &);
    friend bool operator==(const Fraction&, const Fraction &);
    friend bool operator!=(const Fraction& f1, const Fraction & f2);
    friend int get_GCD(const Fraction&, const Fraction&);
    friend Fraction reduce (const Fraction &);
    friend std::string get_sign (Fraction );
    friend std::string to_string (Fraction&);
    
private:
    int numerator;
    int denominator;
public:
    Fraction(int n, int d=1) throw (InvalidArgumentException);
    ~Fraction() = default;
    float get_value();
    Fraction& operator=(const Fraction&);
    Fraction& inverse() throw (InvalidArgumentException);
};

#endif // _FRACTION_H_
