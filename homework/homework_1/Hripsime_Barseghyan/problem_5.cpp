#include <iostream>

int input(std::string msg);
int computeGCD(int a, int b);
int computeLCM(int a, int b);

int main(){
    int a = input("Insert first number");
    int b = input("Insert second number");
    std::cout <<"GCD: " <<computeGCD(a, b)<<std::endl;
    std::cout <<"LCM: " <<computeLCM(a, b)<<std::endl;


    std::cout << "Complexity for Euclid's algorithm: O(log10(min(a, b)))" << std::endl;
    std::cout << "Complexity for primeFactorizing(worst case): O(max(a, b))." << std::endl;

    return 0;
}


int computeGCD(int a, int b){
    int c;
    if (a < b)
    {
        c = a;
        a = b;
        b = c;
    }
    while (b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }
    
    return a;
}


int computeLCM(int a, int b){
    return (a*b)/computeGCD(a,b);
}


int input(std::string msg) {
    if (!msg.empty()) {
        std::cout << msg << ": ";
    }
    double value;
    do
    {
        std::cin >> value;
        if(value <= 0)  std::cout <<  "Please insert a positive number: "; 
    } while (value <= 0);
    
    return value;
}