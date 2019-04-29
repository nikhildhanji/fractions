#include "Fraction.h"

Fraction::Fraction(int numerator, int denominator) throw (InvalidArgumentException)
    : numerator{numerator}, denominator{denominator} 
{
    if(denominator == 0){
        throw InvalidArgumentException{};
    }
}

float Fraction::get_value(){
    return static_cast<float>(numerator)/denominator;
}
Fraction& Fraction::operator=(const Fraction& f){
    this->numerator = f.numerator;
    this->denominator = f.denominator;
    return *this;
}
Fraction& Fraction::inverse() throw (InvalidArgumentException){
    int n = this->numerator;
    int d =  this->denominator;
    n=n+d;
    d=n-d;
    n=n-d;
    if(d==0)
        throw InvalidArgumentException{};
    this->numerator = n;
    this->denominator = d;
    return *this;
}

