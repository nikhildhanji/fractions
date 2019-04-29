#ifndef _FRACTION_UTIL_H_
#define _FRACTION_UTIL_H_
#include "Fraction.h"
#include <vector>
static constexpr const char* negative_sign = "-";
static constexpr const char* positive_sign = "";
std::ostream &operator<<(std::ostream &, const Fraction &);
int get_GCD(const Fraction&, const Fraction&);
Fraction operator+(const Fraction&, const Fraction &);
Fraction operator-(const Fraction&, const Fraction &);
Fraction operator*(const Fraction&, const Fraction &);
Fraction operator/(const Fraction&, const Fraction &)throw (InvalidArgumentException);
bool operator<(const Fraction&, const Fraction &);
bool operator>(const Fraction&, const Fraction &);
bool operator==(const Fraction&, const Fraction &);
bool operator!=(const Fraction& f1, const Fraction & f2);

Fraction reduce (const Fraction &);
std::string to_string (Fraction&);
std::string get_sign (Fraction );
#endif // _FRACTION_UTIL_H_
