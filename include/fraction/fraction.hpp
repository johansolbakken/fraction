#pragma once

#include <iostream>

namespace frac
{

    long lcd(long a, long b);

    struct fraction
    {
        long numerator;
        long denominator;

        fraction();
        explicit fraction(long a, long b);
        explicit fraction(double d);
        void increase(long c);
        void decrease(long c);
        long gcd();
        void normalize();
        operator double();
    };

    fraction operator*(const fraction &a, const fraction &b);
    fraction operator/(const fraction &a, const fraction &b);
    std::ostream &operator<<(std::ostream &stream, const fraction &frac);
    fraction operator+(const fraction &a, const fraction &b);
}
