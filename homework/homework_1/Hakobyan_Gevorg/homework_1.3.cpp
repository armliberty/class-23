#include<iostream>
#include<vector>

//ALias
using IntVector = std::vector<int>;

IntVector primeFactorization(int);
void findNextPrime(int,int, IntVector&);
int quantityOfPrime(int, int, IntVector&);
bool isPrime(int);
bool hasPerfectSquare(double num, long double delta);

int main() {
    int num;
    std::cout << "Input the number: ";
    std::cin >> num;

    IntVector factors = primeFactorization(num);
    std::cout << num << " = [ ";
    for (const auto& factor : factors) {
        std::cout << factor << ", ";
    }
    std::cout << "]" << "\n";
    IntVector list;
    findNextPrime(num, 1,list);
    return 0;
};

IntVector primeFactorization(int num) {
    int firstPrime{1};
    IntVector listOfPrimes;
    findNextPrime(num,firstPrime, listOfPrimes);
    return listOfPrimes;
}

void findNextPrime(int num, int i,IntVector& listOfPrimes) {

    //if the number already became 
    if (1 == num) {
        return;
    }

    while(true) {
        if (isPrime(i) && !(num % i)) {
            break;
        }
        i++;
    }
    int firstFactor{i};
    int tempNum = quantityOfPrime(firstFactor, num, listOfPrimes);
    i++;
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


bool hasPerfectSquare(double num, long double delta) {
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


