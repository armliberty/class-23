#include "includes.hpp"

std::vector<int> primeFactorize(int x);

int findGCD(const std::vector<int>& factorsA, const std::vector<int>& factorsB)
{
    auto result = 1;
    auto i = 0;
    auto j = 0;

    while (i < factorsA.size() && j < factorsB.size())
    {
        if (factorsA[i] == factorsB[j])
        {
            result *= factorsA[i];
            ++i;
            ++j;
        }
        else if (factorsA[i] < factorsB[j])
            ++i;
        else
            ++j;
    }
    return result;
}

int computeGCD(int a, int b)
{
    auto factorsA = primeFactorize(a);
    auto factorsB = primeFactorize(b);
    auto gcd = findGCD(factorsA, factorsB);
    return gcd;
}

// int main()
// {
//     int a, b;

//     std::cout << "Enter a and b: ";
//     std::cin >> a >> b;
//     std::cout << "GCD is: " << computeGCD(a, b) << std::endl;
// }