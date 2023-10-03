#include <cmath>
#include <iostream>

int input(const std::string &msg);
bool isPrime(const int& number);

int main() {
    const auto number = input("Input number you want to check");

    if (isPrime(number)) {
        std::cout << "The number is Prime\n";
    }
    else {
        std::cout << "The number is NOT Prime\n";
    }
}

bool isPrime(const int& number) {
    if(number < 2) {
        return false;
    }
    const int sqRoot = sqrt(number);

    for (int i = 2; i <= sqRoot; ++i) {
        if (number % i == 0) {
            return false;
        }
    }

    return true;
}

int input(const std::string &msg) {
    if (!msg.empty()) {
        std::cout << msg << ": ";
    }

    int value;
    std::cin >> value;

    return value;
}
