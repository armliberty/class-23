#include <cmath>
#include <iostream>
#include <vector>

int input(const std::string &msg);
bool isPrime(const int& number);
std::vector<int> primeFactorize(int number);
int computeGCD(int a, int b);
int computeLCM(int a, int b);

int main() {
    auto firstDigit = input("Input first digit");
    auto secondDigit = input("Input second digit");

    auto gcd = computeGCD(firstDigit, secondDigit);
    auto lcm = computeLCM(firstDigit, secondDigit);

    if(gcd == -1)
        std::cout << "The numbers haven`t GCD" << std::endl;
    else {
        std::cout << "the GCD = " << gcd << std::endl;
    }

    std::cout << "the LCM = " << lcm << std::endl;
    
    return 0;
}

int computeGCD(int a, int b) {
    const auto factorizeOfA = primeFactorize(a);
    const auto factorizeOfB = primeFactorize(b);

    //return -1 if numbers havent GCD
    if(factorizeOfA.empty() && factorizeOfB.empty()) {
        return -1;
    }

    int gcd = 1;
    int j = 0;

    for(int i = 0; i < factorizeOfA.size(); ++i) {
        for(; j < factorizeOfB.size(); ++j) {
            if(factorizeOfA[i] > factorizeOfB[j]) {
                continue;
            }
            else if(factorizeOfA[i] < factorizeOfB[j]) {
                break;
            }
            else {
                gcd *= factorizeOfA[i];
                j++;
                break;
            }
        }        
    }

    return gcd;
}

int computeLCM(int a, int b) {
    if (isPrime(a) && isPrime(b)) {
        return (a * b);
    }
    else if (isPrime(a) && (b % a == 0)) {
        return (b);
    }
    else if (isPrime(b) && (a % b == 0)) {
        return (a);
    }
    else {
        return ((a * b) / computeGCD(a, b));
    }
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
