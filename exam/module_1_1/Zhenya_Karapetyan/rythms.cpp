#include "includes.hpp"

void input(int &a1, int &b1, int &a2, int &b2)
{
    a1 = 0;
    b1 = 0;
    a2 = 0;
    b2 = 0;
    while (a1 <= 0 && b1 <= 0 && a2 <= 0 && b2 <= 0)
    {
        std::cout << "Enter a1, b1 that are > 0" << std::endl;
        std::cin >> a1 >> b1;
        std::cout << "Enter a2, b2 that are > 0" << std::endl;
        std::cin >> a2 >> b2;
    }
}

int LCM(int a, int b)
{
    auto gcd = euclidsGCD(a, b);
    return ((a * b) / gcd);
}

int compute_tacts(int a1, int b1, int a2, int b2)
{
    int k1;
    int k2;
    int total_time_1;
    int total_time_2;
    int lcm_denom;

    lcm_denom = LCM(b1, b2);
    k1 = lcm_denom / b1;
    k2 = lcm_denom / b2;
    total_time_1 = k1 * a1;
    total_time_2 = k2 * a2;
    return (std::min(total_time_1, total_time_2));
}

int main()
{
    int a1;
    int b1;
    int a2;
    int b2;
    int result;

    input(a1, b1, a2, b2);
    result = compute_tacts(a1, b1, a2, b2);
    std::cout << "Result is " << result << std::endl;
    return (0);
}