#include <iostream>
#include <cmath>

double input(std::string msg);
double cubeRoot(double x, double delta);

int main()
{
    double x = input("Insert a number");
    double delta = 0.00001;
    if (x >= 0)
        std::cout << "Cube root of inserted number: " << cubeRoot(x, delta) << std::endl;
    else
        std::cout << "Cube root of inserted number: -" << cubeRoot(x, delta) << std::endl;

    std::cout << "Cube Root of inserted number(cmath): " << std::pow(x, 1 / 3.0) << std::endl;

    return 0;
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

double cubeRoot(double x, double delta)
{
    double res = fabs(x), prevRes, func, derivfunc;
    if (x == 0)
        return 0;

    do
    {
        func = res * res * res - fabs(x);
        derivfunc = res * res * fabs(x);
        prevRes = res;
        res = res - func / derivfunc;
    } while (fabs(res - prevRes) > delta);

    return res;
}