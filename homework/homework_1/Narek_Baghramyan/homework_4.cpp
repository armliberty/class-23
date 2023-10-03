#include <cmath>
#include <iostream>
#include <vector>

int computeGCD(int a, int b);
int computeLCM(int a, int b);
std::vector<int> primeFactorize(int n);

int main() {
    int a,b;
    std::cout << "a = "; std::cin >> a;
    std::cout << "b = "; std::cin >> b;
    int gcd = computeGCD(a, b); 
    std::cout << "GCD = " << gcd << std::endl;
    int lcm = computeLCM(a, b);
    std::cout << "LCM = " << lcm << std::endl;
}

int computeGCD(int a, int b) {
    std::vector<int> a_factorize = primeFactorize(a);
    std::vector<int> b_factorize = primeFactorize(b);

    int gcd = 1, i = 0, j = 0;

        while(i < a_factorize.size() && j < b_factorize.size()) {
          if(a_factorize[i] < b_factorize[j])
              i++;   
          else if(a_factorize[i] > b_factorize[j])
              j++;
          else {
              gcd *= a_factorize[i]; 
              i++;
              j++;
          }
        }
    return gcd;
}

int computeLCM (int a, int b) {
   int lcm = (a * b) / computeGCD(a,b);
   return lcm;
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