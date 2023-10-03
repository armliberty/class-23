#include <iostream>
#include <cmath>

double CubeRoot (double x, double delta);

double sin_ (double x,  double delta);

int main ()
{
    double delta , x_cr, x_s ;
    std::cout << "delta = " ; std::cin >> delta;
    std::cout << "Number for CubeRoot = "; std::cin>> x_cr;
    std::cout << "CubeRoot is: " << CubeRoot(x_cr , delta) << std::endl;
    std::cout << "pow (x,1/3) = " << std::pow(x_cr , 1.0 / 3.0) << std::endl;
    std::cout << "Number for sin = "; std::cin >> x_s;
    std::cout << "the sin is: " << sin_ (x_s , delta) << std::endl;
        return 0;
    
}

double CubeRoot(double x, double delta)
{
    auto x_now = x;
    double x_new;

    do  {
        x_new = x_now;
        x_now = x_new + (x/(x_new * x_new) - x_new) /3;
    }
    while (std::abs (x_now - x_new) > delta);
    return x_new;
}


double sin_ (double x, double delta)
{
    x = (x * M_PI) / 180;

    do {
        x = x - (std::sin(x) - x)    /   (std::cos(x) -1);

        if(std::abs(std::sin(x) - x) < delta)

        break;

    }
    while (true) ; 
    return x;
}