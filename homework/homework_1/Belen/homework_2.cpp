#include <iostream>

bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }

    for (int divider; divider  < num; divider++) {
        if (num % divider == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int num;
    std::cout << "Enter an integer: ";
    std::cin >> num;

    if (isPrime(num)) {
        std::cout << num << " is a prime number.";
    } else {
        std::cout << num << " is not a prime number.";
    }

    return 0;
}