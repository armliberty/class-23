#include<iostream>
#include<vector>

//ALias
using IntVector = std::vector<int>;

IntVector getFactors(int, IntVector&);
void findNextPrime(int,int, IntVector&);
int quantityOfPrime(int, int, IntVector&);
bool isPrime(int);
std::pair<int, bool> ifAnyIsPrime(int, int);
bool hasPerfectSquare(double num, long double delta);
int computeGCD(const IntVector, const IntVector);
int computeLCM(int , int, int);

int main() {
    int num1;
    int num2;
    std::cout << "Input the numbers: ";
    std::cin >> num1 >> num2;
    if (ifAnyIsPrime(num1, num1).second) {
        std::cout << "GCD of " << num1 << " and " << num2 << ": " << ifAnyIsPrime(num1, num1).first << "\n";
        return 0;
    }

    IntVector listOfPrimesOfNum1;
    IntVector factors1 = getFactors(num1, listOfPrimesOfNum1);

    IntVector listOfPrimesOfNum2;
    IntVector factors2 = getFactors(num2, listOfPrimesOfNum2);

    int gcd = computeGCD(listOfPrimesOfNum1, listOfPrimesOfNum2);
    int lcm  = computeLCM(num1, num2, gcd);
    std::cout << "GCD of " << num1 << " and " << num2 << ": " << gcd << "\n";
    std::cout << "LCM of " << num1 << " and " << num2 << ": " << lcm << "\n";
    return 0;
};

IntVector getFactors(int num, IntVector& listOfPrimesOfNum1) {
    int firstPrime{0};
    findNextPrime(num,firstPrime, listOfPrimesOfNum1);
    return listOfPrimesOfNum1;
}

void findNextPrime(int num, int i, IntVector& listOfPrimesOfNum1) {

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
    int tempNum = quantityOfPrime(firstFactor, num, listOfPrimesOfNum1);
   findNextPrime(tempNum,i, listOfPrimesOfNum1); 
}



int quantityOfPrime(int prime, int num, IntVector& listOfPrimesOfNum1) {
    //finding quantity of prime in num
    int remainder{0};
    while (!(remainder)) {
        listOfPrimesOfNum1.push_back(prime);
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

std::pair<int, bool> ifAnyIsPrime(int num1, int num2) {
    std::pair<int, bool> primeNumber;
    if (isPrime(num1)) {
        primeNumber.first = num1;
        primeNumber.second = true;
        return primeNumber;
    }
    
    if (isPrime(num2)) {
        primeNumber.first = num2;
        primeNumber.second = true;
        return primeNumber;
    }

    primeNumber.first = 0;
    primeNumber.second = false;
    return primeNumber;
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


int computeGCD(const IntVector list1, const IntVector list2) {

    int sizeList1 = list1.size();
    int sizeList2 = list2.size();
    IntVector maxVector; 
    IntVector minVector; 

    int maxList;
    int minList;
    int GCD{1};

    if (sizeList1 > sizeList2) {
        maxList = sizeList1;
        minList = sizeList2;
        minVector = list2;
        maxVector = list1;
    } else {
        maxList = sizeList2;
        minList = sizeList1;
        minVector = list1;
        maxVector = list2;
    }

    for (int i = 0; i < minList; ++i) {
        for (int j = 0; j < maxList; ++j) {
            if (minVector[i] == maxVector[j]) {
                GCD *= minVector[i];
                break;
            }
        }
    }
    return GCD;
}

int computeLCM(int num1, int num2, int GCD) {
    int lcm = (num1 * num2) / GCD;
    return lcm;
}
