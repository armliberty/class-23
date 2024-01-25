#include "includes.hpp"

void printFactors(std::vector<int> factors)
{
    int i = -1;
    int size = factors.size();

    std::cout << "Prime factors are: ";
    while (++i < size)
    {
        std::cout << factors[i];
        if (i != size - 1)
            std::cout << "*";
    }
    std::cout << std::endl;
}

std::vector<int> primeFactorize(int x)
{
    std::vector<int> factors;
    int i = 2;

    while (i <= x)
    {
        if (x % i == 0 && isPrime(i))
        {
            factors.push_back(i);
            x /= i;
        }
        else
            ++i;
    }
    return factors;
}

// int main()
// {
//     int x;

//     std::cout << "Enter the number x to test it: ";
//     std::cin >> x;
//     printFactors(primeFactorize(x));
// }