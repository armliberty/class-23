#include <iostream>
#include <cmath>

double CubeRoot (double x, double delta);

int main ()
{
    double delta = 0.0001, n;
    std::cout << "n= "; std::cin>> n;
    std::cout << "CubeRoot is: " << CubeRoot(n , delta) << std::endl;
    std::cout << std::pow(n , 1.0 / 3.0) << std::endl;
        return 0;
    
}

double CubeRoot(double x, double delta)
{
    auto current_value = x;
    double previous_value;

    do  {
        previous_value = current_value;
        current_value = previous_value + (x/(previous_value * previous_value) - previous_value) /3;
    }
    while (std::abs (current_value - previous_value) > delta);
    return current_value;
}