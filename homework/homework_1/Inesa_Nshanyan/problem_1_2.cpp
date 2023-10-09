#include <iostream>
#include <cmath>

double sine(double x, double delta);

int main() {
    double x, delta = 0.00001;
    std::cout << "Enter x = ";
    std::cin >> x;
    std::cout << "sine = " << sine(x, delta) << std::endl;
    std::cout << "sin = " << sin(x) << std::endl;
}
double sine(double x, double delta)
{
    double func, derivative;
    do {
        func = sin(x) - x;
        derivative = cos(x) - 1;
        x = x - (func / derivative);
    } while (abs(func) > delta);
    return x;
}

