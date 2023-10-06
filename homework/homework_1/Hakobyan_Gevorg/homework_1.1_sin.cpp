#include<cmath>
  #include<iostream>
  
double getSinValue(double,double);
  
int main() {
    int num;
    std::cout << "Input the number: ";
    std::cin >> num;
  
    int delta;
    std::cout << "\n" << "Input the delta: ";
    std::cin >> delta;
  
    std::cout << "sin(" << num << ") = " << getSinValue(num, delta) << "\n";
    return 0;
}
  
double getSinValue(double num, double delta) {
    double initialGues {1};
    num = (num * M_PI) / 180.0;
  
    while(true) {
        double fx = sin(initialGues) - sin(num);
        double derivative = cos(initialGues);
        initialGues -= fx / derivative;

        if(fabs(fx) <= delta) {
            break;
        }
    }
    return sin(initialGues);
}
  
