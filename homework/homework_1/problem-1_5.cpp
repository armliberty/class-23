#include <cmath>
#include <iostream>
#include <vector>

int computeGCD(int a, int b);
int computeLCM(int a, int b);
std::vector<int> primeFactorize(int n);

int main() {
   int a,b;
   std::cout << "a="; std::cin >> a;
   std::cout << "b="; std::cin >> b;
   int GCD = computeGCD(a, b); 
   std::cout << "GCD = " << GCD << std::endl;
   int LCM = computeLCM(a, b);
   std::cout << "LCM = "<< LCM << std::endl;  
}

int computeGCD(int a, int b) { 
  int t;
  while ((a % b) > 0) {
    t = a % b;
    a = b;
    b = t;
  }
  return b;
}

int computeLCM(int a, int b) {
    int LCM = (a * b) / computeGCD(a,b);
    return LCM;
}

std::vector<int> primeFactorize(int n) {
    std::vector<int> vec;

    while(n % 2 == 0) {
        n = n / 2;
        vec.push_back(2);   
    }

    for(int i = 3; i <= std::sqrt(n); i+=2) {
        while(n % i == 0) {
            vec.push_back(i);
            n = n / i;
        } 
    } 

    if(n >= 2) {
        vec.push_back(n);
    }

    return vec;
}

