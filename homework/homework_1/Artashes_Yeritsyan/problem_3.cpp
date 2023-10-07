#include <cmath>
#include <iostream>
#include <vector>

int input(const std::string &msg);
bool isPrime(const int& number);
std::vector<int> primeFactorize(int number);

int main() {
    auto number = input("Input number you want factorize");
    const auto primeNumbers = primeFactorize(number);

    if(primeNumbers.empty()) {
        std::cout << "The number is Prime\n";
    }
    else {
        std::cout << "Prime factorize of " << number << ". \n\t\t\t";

        int size = primeNumbers.size();
        for(int i = 0; i < size; ++i) {
            std::cout << primeNumbers[i];
            if(i != size - 1) {
                std::cout << " * "; 
            }
        }
        std::cout << "\n";
    }
    
    return 0;
}

std::vector<int> primeFactorize(int number) {
    if (isPrime(number)) {
        return std::vector<int>();
    }

    std::vector<int> primeNumbers;
    const int half = number / 2;
    
    int i = 2;
    while (i <= half) {
        if (isPrime(i) && number % i == 0) {
            number = number / i;
            primeNumbers.push_back(i);
            i = 1;
        }
        i++;
    }
            
    return primeNumbers;
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
