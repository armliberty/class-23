#include <iostream>
#include <vector>

std::vector<int> Primes(int n) {
    std::vector<bool> is_prime(n, true);
    is_prime[0] = is_prime[1] = false;
    //If a number is not divisible by any prime number that precedes it, it will not be divisible by any composite number that precedes it.
    for (int i = 2; i * i <= n; ++i) { 
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    std::vector<int> primes;
    for (int i = 2; i <= n; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
    return primes;
}

void PrintPrimes(std::vector<int> primes){
    for (int i = 0; i<primes.size(); i++) {
        std::cout << primes[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int n = 100;
    PrintPrimes(Primes(n));
    return 0;
}
