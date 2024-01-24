#include <iostream>
#include <cmath>
double sine (double x,  double delta);


int main ()
{
    double delta = 0.0001, n;
    std::cout << "n = "; std::cin >> n;
    std::cout << "the sin root is: " << sine (n , delta) << std::endl;
    return  0;

}

double sine (double x, double delta)
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