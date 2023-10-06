#include <iostream>


int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
   return a;
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main(){
    int num1, num2;
    std::cout << "Enter number1: ";
    std::cin >> num1;
    std::cout << "Enter number2: ";
    std::cin >>  num2;

    std::cout<<"GCD = "<< gcd(num1, num2)<<std::endl;
    std::cout<<"LCM = "<< lcm(num1, num2)<<std::endl;
    std::cout<<"algorithm complexity Ewclide = O(log(a) + log(b))"<<std::endl;
    std::cout<<"algorithm complexity primeFactorize = O(log(a) + (a)^2 + log(b) + (b)^2)"<<std::endl;

}