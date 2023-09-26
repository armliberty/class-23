#include<iostream>
#include<vector>

//Alias
using IntVector = std::vector<int>;

IntVector getFactors(int, IntVector&);
void findNextPrime(int,int, IntVector&);
int quantityOfPrime(int, int, IntVector&);
bool isPrime(int);
bool hasPerfectSquare(double num, long double delta);

int main() {
    int num;
    std::cout << "Input the number: ";
    std::cin >> num;

    IntVector listOfPrimes;
    IntVector factors = getFactors(num, listOfPrimes);

    std::cout << num << " = " << "[ ";
    for (const auto& factor : factors) {
        std::cout << factor << ", ";
    }
    std::cout << "]" << "\n";
    return 0;
};

IntVector getFactors(int num, IntVector& listOfPrimes) {
    //checking if prime
    if (isPrime(num)) {
        listOfPrimes.push_back(num);
        return listOfPrimes;
    }
    int firstPrime{0};
    findNextPrime(num,firstPrime, listOfPrimes);
    return listOfPrimes;

}

void findNextPrime(int num, int i, IntVector& listOfPrimes) {

     //finding next prime in the list
    int firstFactor{0};
    IntVector primes {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
    for (; i < primes.size(); ++i) {
        if (!(num % primes[i])) {
            firstFactor = primes[i];
            break;
        }
    }

    if (!firstFactor) {
        return;
    }
    //if the number already became 
    i++;
    int tempNum = quantityOfPrime(firstFactor, num, listOfPrimes);
   findNextPrime(tempNum,i, listOfPrimes); 
}



int quantityOfPrime(int prime, int num, IntVector& listOfPrimes) {
    //finding quantity of prime in num
    int remainder{0};
    while (!(remainder)) {
        listOfPrimes.push_back(prime);
        num /= prime;
        remainder = num % prime;
    }
    return num;
}

bool isPrime(int num) {
    if (hasPerfectSquare(num, 0.000001)) {
        return false;
    }

    for (int i = 2; i < num / 2; ++i) { 
        if (!(num % i)) {
            return false;
        }
    }
    return true;
}

bool hasPerfectSquare(double num, long double delta)  {
    long double x {num};
    long double root;
    while(true) {
        root = 0.5 * (x + (num / x));
        if (abs(root - x) < delta) {
            break;
        }
        x = root;
    }

    if (root - int(root) < 0.1) {
        return true;
    }
    return false;
}


