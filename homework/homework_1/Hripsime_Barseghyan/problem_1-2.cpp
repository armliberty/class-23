#include <iostream>
#include <cmath>

double input(std::string msg);
double sine(double x, double delta);

int main()
{
    double x = input("Insert a number");
    double delta = 0.00001;
    std::cout << "Result: " << sine(x, delta) << std::endl;
}

double input(std::string msg)
{
    if (!msg.empty())
    {
        std::cout << msg << ": ";
    }
    double value;
    std::cin >> value;

    return value;
}

double sine(double x, double delta)
{
    double res = x, func, derivFunc;

    while (true)
    {
        func = std::sin(res) - res;
        derivFunc = std::cos(res) - 1;

        if (std::abs(func) < delta)
            return res;

        res = res - func / derivFunc;
    }

    return res;
}
