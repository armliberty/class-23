#include <iostream>
#include <cmath>

double sine(double x, float delta)
{
    x = (x*M_PI)/180;

    do 
    {
        x = x - (std::sin(x) - x)/(std::cos(x) - 1);
       
        if(std::abs(std::sin(x) - x) < delta)
            break;
        
    }
    while (true);
    
    std::cout<<"the sin root is: ";
    return x;
}


int main()
{
    double n;
    std::cout<<"Enter the number:";
    std::cin>>n;
    float l = 0.0001;
    
    std::cout<<sine(n,l)<<std::endl;
    
    return 0;
}