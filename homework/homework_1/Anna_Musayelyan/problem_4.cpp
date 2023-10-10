#include <iostream>
#include<algorithm>
#include "prime_checker.h"
// Function to calculate GCD using prime factorization
int calculateGCD(int num1, int num2) {
    std::vector<int> factors1 = primeFactorize(num1);
    std::vector<int> factors2 = primeFactorize(num2);

    int gcd = 1;

    for (int factor : factors1) {
        auto it = std::find(factors2.begin(), factors2.end(), factor);
        if (it != factors2.end()) {
            gcd *= factor;
            factors2.erase(it);
        }
    }

    return gcd;
}

// Function to calculate LCM using GCD
int calculateLCM(int num1, int num2) {
    int gcd = calculateGCD(num1, num2);
    return (num1 * num2) / gcd;
}

int main() {
    int num1, num2;

    std::cout << "Enter two positive integers: ";
    std::cin >> num1 >> num2;

    if (num1 < 0 || num2 < 0) {
        std::cout << "Please enter positive integers." << std::endl;
        return 1;
    }

    int gcd = calculateGCD(num1, num2);
    int lcm = calculateLCM(num1, num2);

    std::cout << "GCD of " << num1 << " and " << num2 << " is: " << gcd << std::endl;
    std::cout << "LCM of " << num1 << " and " << num2 << " is: " << lcm << std::endl;

    return 0;
}

