#include <iostream>
#include <vector>

//ALias
using IntVector = std::vector<int>;

//primeFactorization 
IntVector getFactors(int, IntVector&, int&);
void findNextPrime(int,int, IntVector&, int&);
int quantityOfPrime(int, int, IntVector&, int&);
bool isPrime(int, int&);
std::pair<int, bool> ifAnyIsPrime(int, int, int&);
bool hasPerfectSquare(double num, long double delta, int&);
int computeGCD(const IntVector, const IntVector, int&);

//Eucludis
int computeGCD(int, int, int&);
int computeLCM(int, int, int, int&);
std::pair<int,int> max_min(int, int, int&);

int main() {
    int num1;
    int num2;
    std::cout << "Input numbers: ";
    std::cin >> num1 >> num2;

    int iteration2{0};
    int iteration1{0};

    std::cout << "The GCD of " << num1 << " and " << num2 << ": " << computeGCD(num1,num2, iteration1) << "\n";
    std::cout << "The LCM of " << num1 << " and " << num2 << ": " << computeLCM(num1,num2, computeGCD(num1, num2, iteration1), iteration1) << "\n";
    //PrimeFactorization
    std::cout << "The GCD of " << num1 << " and " << num2 << ": " << computeGCD(num1,num2, iteration2) << "\n";

    std::cout << "Number of iterations of primeFactorization is: " << iteration2 << "\n";
    std::cout << "Number of iteratins of Eucluidis is: " << iteration1 << "\n";
    return 0;
}

//PrimeFactorization implementation
IntVector primeFactorization(int num,int& iteration2) {
    int firstPrime{1};
    IntVector listOfPrimes;
    findNextPrime(num,firstPrime, listOfPrimes, iteration2);
    return listOfPrimes;
}

void findNextPrime(int num, int i,IntVector& listOfPrimes, int& iteration2) {
    //if the number already became 
    if (1 == num) {
        return;
    }

    while(true) {
        if (isPrime(i, iteration2) && !(num % i)) {
            break;
        }
        i++;
        iteration2++;
    }
    int firstFactor{i};
    int tempNum = quantityOfPrime(firstFactor, num, listOfPrimes, iteration2);
    i++;
    findNextPrime(tempNum,i, listOfPrimes, iteration2);
}



int quantityOfPrime(int prime, int num, IntVector& listOfPrimesOfNum1,int& iteration2) {
    //finding quantity of prime in num
    int remainder{0};
    while (!(remainder)) {
        listOfPrimesOfNum1.push_back(prime);
        num /= prime;
        remainder = num % prime;
        iteration2++;
    }
    return num;
}

bool isPrime(int num, int& iteration2) {
    if (hasPerfectSquare(num, 0.000001, iteration2)) {
        return false;
    }

    for (int i = 2; i < num / 2; ++i) { 
        if (!(num % i)) {
            return false;
        }
        iteration2++;
    }
    return true;
}

std::pair<int, bool> ifAnyIsPrime(int num1, int num2,int& iteration2) {
    std::pair<int, bool> primeNumber;
    if (isPrime(num1, iteration2)) {
        primeNumber.first = num1;
        primeNumber.second = true;
        return primeNumber;
    }
    
    if (isPrime(num2, iteration2)) {
        primeNumber.first = num2;
        primeNumber.second = true;
        return primeNumber;
    }

    primeNumber.first = 0;
    primeNumber.second = false;
    return primeNumber;
}

bool hasPerfectSquare(double num, long double delta,int& iteration2) {
    long double x {num};
    long double root;
    while(true) {
        root = 0.5 * (x + (num / x));
        if (abs(root - x) < delta) {
            break;
        }
        x = root;
        iteration2++;
    }

    if (root - int(root) < 0.1) {
        return true;
    }
    return false;
}

//Eucluidis
int computeGCD(int num1, int num2, int& iteration1) {
    if (num1 == num2) {
        return num1;
    };
    int max = max_min(num1, num2, iteration1).first;
    int min = max_min(num1, num2, iteration1).second;
    int remainder{1};
    int tmp {0};

    while(min) {
        tmp = max;
        max  = min;
        min = (tmp % min);
        iteration1++;
    }
    return max;
}


std::pair<int, int> max_min(int num1, int num2,int& iteration1) {
    std::pair<int, int> max_min;
    if (num1 > num2) {
        max_min.first = num1;
        max_min.second = num2;
        return max_min;
    }
    max_min.first = num2;
    max_min.second = num1;
    return max_min;
}

int computeLCM(int num1, int num2, int GCD, int& iterations) {
    int lcm = (num1 * num2) / GCD;
    return lcm;
}
