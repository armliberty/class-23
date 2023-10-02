#include <iostream>
#include <vector>
#include <cmath>

bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

std::vector<int> primeFactorize(int num) {
    std::vector<int> primeFactors;
    for (int i = 2; i <= num; i++) {
        while (num % i == 0 && isPrime(i)) {
            primeFactors.push_back(i);
            num /= i;
        }
    }
    return primeFactors;
}

int main() {
    int num;
    std::cout << "Enter the number: ";
    std::cin >> num;

    std::vector<int> primeFactors = primeFactorize(num);
    std::cout << "Prime factors of " << num << ": ";
    for (int factor : primeFactors) {
        std::cout << factor << " ";
    }
    std::cout <<"\n";

    return 0;
}





