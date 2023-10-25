#include <iostream> 
#include <cmath>
 
double sine(double x, double delta) { 
    double x1;
 
    while (abs(x-x1)>delta) { 
        x1 = x - ((sin(x)-x) / (cos(x)-1)); 
    }
 
    return x1; 
} 
 
int main() {
    double x;
    std::cout <<"input the value of x :  ";
    std::cin >> x;

    double delta;
    std::cout <<"input the value of delta :  ";
    std::cin >> delta;

    double result = sine(x,delta);
    std::cout <<" result is :   " << result << std::endl;

    return 0;
}