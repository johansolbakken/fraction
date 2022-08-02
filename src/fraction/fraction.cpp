#include "fraction/fraction.hpp"

#include <iostream>
#include <cassert>

namespace frac
{
    long lcd(long a, long b)
    {
        if (a == 0 || b == 0)
            return 0;
        long absA = std::abs(a);
        long absB = std::abs(b);
        long high = std::max(absA, absB);
        long low = std::min(absA, absB);
        int lcd = high;
        while ((lcd % low) != 0)
        {
            lcd += high;
        }
        return lcd;
    }

    fraction::fraction()
    {
        numerator = 0;
        denominator = 1;
    }

    fraction::fraction(long a, long b)
    {
        numerator = a;
        denominator = b;
    }

    fraction::fraction(double d)
    {
        long denom = 1;
        double num = d;
        while (num - std::floor(num) != 0)
        {
            denom *= 10;
            num *= 10.0;
        }
        denominator = denom;
        numerator = static_cast<long>(num);
        normalize();
    }

    void fraction::increase(long c)
    {
        numerator *= c;
        denominator *= c;
    }

    void fraction::decrease(long c)
    {
        assert(c != 0);
        numerator /= c;
        denominator /= c;
    }

    long fraction::gcd()
    {
        long a = numerator;
        long b = denominator;
        long r = 1;

        while ((a % b) > 0)
        {
            r = a % b;
            a = b;
            b = r;
        }

        return b;
    }

    void fraction::normalize()
    {
        decrease(gcd());
    }

    fraction::operator double()
    {
        assert(denominator != 0);
        return static_cast<double>(numerator) / static_cast<double>(denominator);
    }

    fraction operator*(const fraction &a, const fraction &b)
    {
        return fraction{a.numerator * b.numerator, a.denominator * b.denominator};
    }

    fraction operator/(const fraction &a, const fraction &b)
    {
        return a * fraction{b.denominator, b.numerator};
    }

    std::ostream &operator<<(std::ostream &stream, const fraction &frac)
    {
        stream << frac.numerator << "/" << frac.denominator;
        return stream;
    }

    fraction operator+(const fraction &a, const fraction &b)
    {
        fraction result;
        if (a.denominator == b.denominator)
        {
            result = fraction{a.numerator + b.numerator, a.denominator};
        }
        else
        {
            auto ac = a;
            ac.increase(b.denominator);
            auto bc = b;
            bc.increase(a.denominator);
            result = ac + bc;
        }
        result.normalize();
        return result;
    }
}