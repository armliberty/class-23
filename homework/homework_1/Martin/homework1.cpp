#include <iostream>
#include <string>
#include <cmath>

#define PI 3.14159265359

template <typename T>
T input(std::string msg);

double initialGuess(double x);
double cubeRoot(double x, double delta);
double sine(double x, double delta);


int main(){
    // is you input value
    const auto num = input<double>("Input you number");
    // delta is you precision 
    const auto delta = input<double>("Input you delta value");
    std::cout<<"\n"<<cubeRoot(num, delta)<<std::endl;
    
}

template <typename T>
T input(std::string msg) {
    if (!msg.empty()) {
        std::cout << msg << ": ";
    }
    T value;
    std::cin >> value;

    return value;
}

double initialGuess(double x){
    double x0 = 1;    

    while(true){
        if(pow(x0,3) - x > 0){
            x0--;
            return x0;
        }
        else if (pow(x0,3) - x == 0){
            return x0;
        }
        x0++;
    }
}


double cubeRoot(double x, double delta){
    double root;
    // a parametar determins 
    int a = x > 0 ? 1: -1;
    double x0 = a * initialGuess(abs(x));
    
    while(true){

        root = x0 - (pow(x0,3) - x)/(3*pow(x0,2));

        if(fabs(pow(x0,3) - x) <= delta){
            return root;
        }
        x0 = root;
    }
}

double sine(double x, double delta){
    double root;
    double initial = 0.5;

    while(true){
        root = initial - std::tan(initial);
        std::cout<<root<<" should be  "<<std::sin(x)<<"\n";
        if(fabs(root - std::sin(x)) <= delta){
            return root;
        }

        initial = root;
    }
    
}

