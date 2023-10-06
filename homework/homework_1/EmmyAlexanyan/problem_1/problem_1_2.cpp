#include <iostream>
#include <math.h>

double sine(double , double );

int main(){
    double x, delta, last_x;
    std::cout<<"x="; std::cin>>x;
    std::cout<<"delta="; std::cin>>delta;
    last_x = sine(x,delta);
    std::cout<<"x="<<last_x;
    return 0;
}

double sine(double x, double delta){
    double x_next;
    x_next = x - ((sin(x) - x)/(cos(x) - 1));
    
    while(fabs((x_next - x)) > delta){
        x = x_next;
        x_next = x - ((sin(x) - x)/(cos(x) - 1));
    }
    
    return x_next;
}
