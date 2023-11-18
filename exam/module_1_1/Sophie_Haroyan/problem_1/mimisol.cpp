#include <cmath>
#include <iostream>
#include <vector>

using TimeSig = std::pair<int, int>;

TimeSig input(const std::string &msg);
bool isPrime(const int& number);
std::vector<int> primeFactorize(int digit);
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
bool isPrime(int digit) {

    int root;
    root = sqrt(digit);

    for (int i = 2; i <= root; ++i) {
        if (digit % i == 0) {
            return false;           
        }
    }

    return true;
}

std::vector<int> primeFactorize(int digit) {

    std::vector<int> commons;
    int half;
    half = digit/2;
    for (int i = half; i>=2; --i) {
        if (digit % i == 0 && isPrime(i))
        {
            commons.push_back(i);
            digit = digit / i;
            i = digit + 1 / 2;
        }
    }
    commons.push_back(digit);
    return commons;
}

int computeGCD(int a, int b) {
    const auto factorize_a = primeFactorize(a);
    
    int gcd = 1;

    for(int i = 0; i < factorize_a.size(); ++i) {
        if (b % factorize_a[i] == 0){
            gcd *= factorize_a[i];
            b = b / factorize_a[i];
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