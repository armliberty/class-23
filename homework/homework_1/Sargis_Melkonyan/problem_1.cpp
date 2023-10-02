/*1. Implement the following functions using Newton's method and compare the 
results with stdandard implementations in <cmath> module:
    ```
    double cubeRoot(double x, double delta);
    double sine(double x, double delta);`
    ```
*/

#include <iostream>
#include <string>
#include <cmath>

double input(std::string);
double cubeRoot(double, double);
double sine(double , double);


int main(){
    const double delta = 0.0001;
    const auto num = input("number = ");
    const auto cube_rout_num = cubeRoot(num, delta);
    const auto sine_num = sine(num, delta);

    std::cout<<"number cube root is: "<<cube_rout_num<<std::endl;
    std::cout<<"sin(x) = number, number is: "<< sine_num<< std::endl;

    return 0;
}


double input(std::string msg) {
    double value;
    std::cout << msg ;
    std::cin >> value;

    return value;    
}


double cubeRoot(double a, double delta){
    double x0 = 1, x1;

    while(true){
            x1 = x0 - ((x0*x0*x0 - a)/(3*x0*x0));
            if(fabs(x0-x1) <= delta)
                break;
            x0 = x1;
    }
    return x1;    
}


double sine(double a, double delta){
    double x0 = 1, x1;

    if(a > 1 || a < -1)
        return NAN;

    while(true){
            if((cos(x0)) != 0){
                x1 = x0 - (sin(x0) - a)/(cos(x0));
                if(fabs(x0-x1) <= delta)
                    break;
                x0 = x1;
            }
            else
                return NAN;
    }
    return x1;
}
