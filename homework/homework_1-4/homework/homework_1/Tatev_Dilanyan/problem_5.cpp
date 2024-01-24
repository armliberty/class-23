#include <iostream>

int euclideanGCD(int a, int b) {
    while (b != 0) {
        int x= b;
        b = a % b;
        a = x;
    }
    return a;
}

int euclideanLCM(int a, int b) {
    return (a * b) / euclideanGCD(a, b);
}

int main() {
    int a, b;
    std::cout << "Enter number 1::  ";
    std::cin >>a;
    std::cout<<"Enter number 2::  ";
    std::cin >>b;

    int gcd = euclideanGCD(a, b);
    int lcm = euclideanLCM(a, b);

    std::cout << "GCD of " << a << " and " << b << " is: " << gcd << std::endl;
    std::cout << "LCM of " << a << " and " << b << " is: " << lcm << std::endl;

    return 0;
}
