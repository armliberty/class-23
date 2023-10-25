#include <iostream>
#include <cmath>

bool isPrime(int num) {
    int i;
    if (num <= 1) {
        return false;
    }
    for (i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
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
        std::cout << num << " is a prime number." << std::endl;
    } else {
        std::cout << num << " is not a prime number." << std::endl;
    }

    return 0;
}
