#include <cmath>
#include <iostream>
double sine(double x, double delta);
int main()
{
    double x,delta;
    std::cout<<"x:";
    std::cin>>x;
    std::cout<<"delta:";
    std::cin>>delta;
    auto x_appr=sine(x,delta);
    std::cout<<"by Newton's algorithm:"<<x_appr<<std::endl;
    std::cout<<"by cmath:"<<sin(x_appr)<<std::endl;
}
double sine(double x,double delta)
{
    double x_appr;
    x_appr=x-(sin(x)-x)/(cos(x)-1);
    while((fabs(x_appr-x))>delta)
    {
        x=x_appr;
        x_appr=x-(sin(x)-x)/(cos(x)-1);
    }
    return x_appr;
}