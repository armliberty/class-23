#include "includes.hpp"

double cubeRoot(double x, double delta)
{
    double prev = 0;
    double guess = x / 2;
    
    while (8)
    {
        prev = guess;
        guess = guess - (guess * guess * guess - x) / (3 * guess * guess);
        if (std::abs(guess - prev) < delta)
            return guess;
    }
    
    return 0;
}

int main()
{
    double x;
    double delta;
    
    std::cout << "Enter x to calculate the cube root of: ";
    std::cin >> x;
    std::cout << "Enter delta for precision: ";
    std::cin >> delta;
    printf("Result is: %f\n", cubeRoot(x, delta));
    return 0;
}