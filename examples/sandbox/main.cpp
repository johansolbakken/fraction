#include <iostream>

#include <fraction/fraction.hpp>

int main()
{
    frac::fraction a{3, 4};
    a.increase(2);

    frac::fraction b{2, 4};
    a = a + b;
    
    std::cout << "A: " << a << std::endl;
    std::cout << "A as double: " << static_cast<double>(a) << std::endl;

    frac::fraction c(0.6);
    std::cout << c << std::endl;

    frac::fraction d(1.0 / 3.0);
    std::cout << d << std::endl;

    auto e = c + d;
    std::cout << e << std::endl;
}