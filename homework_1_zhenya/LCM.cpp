#include "includes.hpp"

int computeLCM(int a, int b)
{
    auto gcd = computeGCD(a, b);
    return ((a * b) / gcd);
}

int main()
{
    int a, b;

    std::cout << "Enter a and b: ";
    std::cin >> a >> b;
    std::cout << "LCM is: " << computeLCM(a, b) << std::endl;
}