#include "includes.hpp"

int nthLucasNmb(int n)
{
    int i = -1;
    int a = 1;
    int b = 3;
    int tmp = b;

    while (++i < n - 2)
    {
        a = a + tmp;
        tmp = b;
        b = a;
    }
    return a;
}

bool isPrime(int x)
{
    if (x <= 1 || (x > 2 && x % 2 == 0))
        return 0;
    else if ((nthLucasNmb(x) - 1) % x == 0)
        return 1;
    else
        return 0;
}

// int main()
// {
//     int x;

//     std::cout << "Enter the number x to test it: ";
//     std::cin >> x;
//     printf("result is bool: %d\n", isPrime(x));
// }