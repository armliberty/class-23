#include <cmath>
#include <iostream>
double cubeRoot(double x, double delta);
int main()
{
   double x,delta;
   std::cout<<"x:";
   std::cin>>x;
   std::cout<<"delta:";
   std::cin>>delta;
   auto cube_root=cubeRoot(x,delta);
   std::cout<<"by Newton's algorithm:"<<cube_root<<std::endl;
   std::cout<<"by cmath:"<<pow(x,1.0/3.0)<<std::endl;
}
double cubeRoot(double x, double delta)
{
    double guess,cube_root;
    std::cout<<"guess:";
    std::cin>>guess;
    cube_root=(2*pow(guess,3)+x)/(3*pow(guess,2));
    while((fabs(cube_root-guess))>delta)
    {
        guess=cube_root;
        cube_root=(2*pow(guess,3)+x)/(3*pow(guess,2));
    }
    return cube_root;
}