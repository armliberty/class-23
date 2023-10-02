#include <iostream>

bool isPrime(int number);
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
    if (isPrime(number)){
        std::cout << number << " is a prime number" << std::endl;
    } else {
        std::cout << number << " is not a prime number" <<std::endl;
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