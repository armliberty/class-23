#include <iostream>
#include <cmath>

double cubeRoot(double x, double delta);

int main()
{
    double x, delta = 0.0001;
    std::cout << "Enter x = ";
    std::cin >> x;
    std::cout << "cubeRoot = " << cubeRoot(fabs(x), delta) << std::endl;
    std::cout << "cubeRoot(cmath) = " << pow(fabs(x), 1 / 3.0) << std::endl;
    return 0;
}

double cubeRoot(double x, double delta)
{
    double x0 = x;
    double prev, func, derivative;
    do{
        func = pow(x0, 3) - fabs(x);
        derivative = 3 * x0 * x0 * fabs(x);
        prev = x0;
        x0 = x0 - (func / derivative);
    } while (fabs(x0 - prev) > delta);
    if (x == 0) {
        return 0;
    }
    return x0;
}


