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

int computeGCD(int a, int b) {
    std::vector<int> primeFactorsA = primeFactorize(a);
    std::vector<int> primeFactorsB = primeFactorize(b);

    int gcd = 1;
    int i = 0, j = 0;

    while (i < primeFactorsA.size() && j < primeFactorsB.size()) {
        if (primeFactorsA[i] == primeFactorsB[j]) {
            gcd *= primeFactorsA[i];
            i++;
            j++;
        } else if (primeFactorsA[i] < primeFactorsB[j]) {
            i++;
        } else {
            j++;
        }
    }

    return gcd;
}


int computeLCM(int a, int b) {
    std::vector<int> primeFactorsA = primeFactorize(a);
    std::vector<int> primeFactorsB = primeFactorize(b);

    int lcm = 1;
    int i = 0, j = 0;

    while (i < primeFactorsA.size() && j < primeFactorsB.size()) {
        if (primeFactorsA[i] == primeFactorsB[j]) {
            lcm *= primeFactorsA[i];
            i++;
            j++;
        } else if (primeFactorsA[i] < primeFactorsB[j]) {
            lcm *= primeFactorsA[i];
            i++;
        } else {
            lcm *= primeFactorsB[j];
            j++;
        }
    }

    while (i < primeFactorsA.size()) {
        lcm *= primeFactorsA[i];
        i++;
    }

    while (j < primeFactorsB.size()) {
        lcm *= primeFactorsB[j];
        j++;
    }

    return lcm;
}

int main() {
    int a, b;
    std::cout << "Enter number 1::  ";
    std::cin >>a;
    std::cout<<"Enter number 2::  ";
    std::cin >>b;

    int gcd = computeGCD(a, b);
    int lcm = computeLCM(a, b);

    std::cout << "GCD of " << a << " and " << b << " is: " << gcd << std::endl;
    std::cout << "LCM of " << a << " and " << b << " is: " << lcm << std::endl;

    return 0;
}
