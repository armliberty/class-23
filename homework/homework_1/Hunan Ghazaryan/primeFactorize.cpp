#include <iostream>
#include <cmath>
#include <vector>

std::vector<int> primeFactorize(int);
bool isPrime(int);

int main() {
    int x;
    std::cout << "Input x: ";
    std::cin >> x;
    std::vector<int> primeRow;
    primeRow = primeFactorize(x);
    for (int i = 0; i < primeRow.size(); ++i) {
        std::cout << primeRow[i] << " ";
    }
    return 0;
}

std::vector<int> primeFactorize(int x) {
    std::vector<int> primeRow {1};
    if (isPrime(x)) {
        primeRow.push_back(x);
        return primeRow;
    }
    int k = 2;
    while (k <= std::sqrt(x)) {
        if (isPrime(k)) {
            if (x % k == 0) {
                primeRow.push_back(k);
                x /= k; 
            }
            else {
                ++k;
            }
        }
        else {
            ++k;
        }
    }
    if (x > 1) {
        primeRow.push_back(x);
    }
    return primeRow;
}

bool isPrime(int x) {
    if (x <= 1) {
        return false;
    }
    int tmp = std::sqrt(x);
    for (int k = 2; k <= tmp; ++k) {
        if (x % k == 0) {
            return false;
        }
    }
    return true;
}
