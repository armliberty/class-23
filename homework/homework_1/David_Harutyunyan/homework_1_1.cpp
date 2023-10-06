#include <iostream>
#include <cmath>

double CubeRoot(double x, float delta)
{ 
    double root = x;
    double previousValue;

    do
        {
            previousValue = root;

            root = previousValue + (x/(previousValue * previousValue) - previousValue)/3;
           
        }
    while(std::abs(root - previousValue) > delta);
    
    return root;
}


int main()
{
    double n;
    std::cout<<"Enter the number:";
    std::cin>>n;
    float l = 0.0001;
    
    std::cout<<"Newton's method: "<<CubeRoot(n,l)<<std::endl;
    std::cout<<"cmath library function: "<<std::pow(n,1/3)<<std::endl;
    return 0;
}

