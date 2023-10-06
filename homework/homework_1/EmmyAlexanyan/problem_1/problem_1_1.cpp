#include <iostream>
#include <math.h>

double cubeRoot(double , double );

int main(){
    double x, delta, last_x;
    std::cout<<"x="; std::cin>>x;
    std::cout<<"delta="; std::cin>>delta;
    last_x = cubeRoot(x,delta);
    std::cout<<"x="<<last_x;
    return 0;
}

double cubeRoot(double x, double delta){
    double x_next;
    x_next = x - ((pow(x,3) - 3)/(3*x*x));
    
    while(fabs((x_next - x)) > delta){
        x = x_next;
        x_next = x - ((pow(x,3) - 3)/(3*x*x));
    }
    
    return x_next;
}
