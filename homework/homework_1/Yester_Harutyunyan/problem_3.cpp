#include <iostream>
#include <vector>
bool isPrime(int number);
std::vector<int> primeFactorize(int number);

template <typename T>
T input(std::string msg) {
    if (!msg.empty()) {
        std::cout << msg << ": ";
    }
    T value;
    std::cin >> value;
    return value;
}

int main() {
    const auto number = input<int>("Please input number");
    if (!isPrime(number)){
        std::vector<int> primeFactors = primeFactorize(number);
        for (const auto element : primeFactors) {
            std::cout << element << " ";
        }
        std::cout << std::endl;  
    } else {
        std::cout << "Error,a prime number is not divisible by factors" <<std::endl;
    }
}

bool isPrime(int number){
    int i;
    for (i = 2; i <= number / 2; i++){
        if (number % i == 0 || number <= 1){
            return false;
        } 
    }
    return true;
}

std::vector<int> primeFactorize(int number) {
    std::vector<int> factors;
    int i,j;
    while (number % 2 == 0) {
        number = number / 2;
        factors.push_back(2);
    }
    for (i = 3; i <= number; i+=2) {
        while (number % i == 0){
            number = number / i;
            factors.push_back(i);
        }
    }  
    return factors;
}
