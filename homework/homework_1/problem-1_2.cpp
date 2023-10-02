#include <iostream>

bool isPrime(int n) {
    if (n <= 1) 
        return false;
    
    for (int i = 2; i <= n; i++) {
        if (n % i == 0) 
            return false;
        
    }
    return true;
}

int main() {
    int n;
    std::cout << "Input: ";
    std::cin >> n;
    
    if (isPrime(n)) {
        std::cout << n << " is a prime number" << std::endl;
    } else {
        std::cout << n << " isn't a prime number" << std::endl;
    }
    
    return 0;
}