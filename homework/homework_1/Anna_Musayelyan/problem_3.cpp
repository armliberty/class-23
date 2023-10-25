#include <iostream>
#include "prime_checker.h"
#include <vector>

std::vector<int> primeFactorize(int n) {
    std::vector<int> factors;

    if (n < 2) {
        return factors;
    }

    for (int i = 2; i <= n; ++i) {
        while (n % i == 0 && check_prime(i)) {
            factors.push_back(i);
            n /= i;
        }
    }
   // factors.erase(std::unique(factors.begin(), factors.end()), factors.end());

    return factors;
}
/*
int main() {
    int num;

    std::cout << "Enter a positive integer: ";
    std::cin >> num;

    if (num < 0) {
        std::cout << "Please enter a positive integer." << std::endl;
        return 1;
    }

    if (num < 2) {
        std::cout << "Prime factorization is not defined for numbers less than 2." << std::endl;
        return 1;
    }

    std::vector<int> primeFactors = primeFactorize(num);

    if (primeFactors.empty()) {
        std::cout << "No prime factors found for " << num << "." << std::endl;
    } else {
        std::cout << "Prime factors of " << num << ": ";
	int previousFactor = -1; 
        for (int factor : primeFactors) {
           if (factor != previousFactor) {
                std::cout << factor << " ";
            }
            previousFactor = factor;
        }
        std::cout << std::endl;
    }

    return 0;
}*/
