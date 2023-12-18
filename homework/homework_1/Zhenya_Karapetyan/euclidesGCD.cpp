#include "includes.hpp"

int euclidsGCD(int a, int b)
{
    auto temp = 0;

    while (b != 0)
    {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}