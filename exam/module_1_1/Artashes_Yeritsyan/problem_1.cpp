#include <cmath>
#include <iostream>
#include <vector>

using TimeSig = std::pair<int, int>;

TimeSig input(const std::string &msg);
bool isPrime(const int& number);
std::vector<int> primeFactorize(int number);
int computeGCD(int a, int b);
int computeLCM(int a, int b);
int computeOverlap(TimeSig firstPair, TimeSig secondPair);

int main() {

    auto firstPair = input("Input FIRST pair seperated with SPACE");
    auto secondPair = input("Input SECOND pair seperated with SPACE");

    const auto overlapTact = computeOverlap(firstPair, secondPair);
    std::cout << "The overlap tact is: " << overlapTact << std::endl;
    
    return 0;
}

int computeOverlap(TimeSig firstPair, TimeSig secondPair)
{
    if (firstPair.second != secondPair.second) {
        auto commonDivisor = computeLCM(firstPair.second, secondPair.second);
        firstPair.first = firstPair.first * commonDivisor/firstPair.second;
        secondPair.first = secondPair.first * commonDivisor/secondPair.second;
    }

    const auto generalTact = computeLCM(firstPair.first, secondPair.first);
    
    return generalTact/firstPair.first;    
}

//the lower functions is copied from my Homework_1/problem_4
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

TimeSig input(const std::string &msg) {
    if (!msg.empty()) {
        std::cout << msg << ": ";
    }

    TimeSig value;
    std::cin >> value.first;
    std::cin >> value.second;

    return value;
}
