#include <iostream>
#include <string>
#include <vector>

std::vector<int> primeFactorize(int number);
int computeGCD(int a, int b);
int euclideanGCD(int a, int b);
int euclideanLCM(int a, int b);
int input(std::string msg);

int main() {
    int a = input("Please input number");
    int b = input("Please input number");
    std::cout << "GCD: " << computeGCD(a,b) <<std::endl;
    std::cout << "Euclidean's GCD: " << euclideanGCD(a,b) <<std::endl;
    std::cout << "Euclidean's LCM: " << euclideanLCM(a,b) <<std::endl;
    std::cout << "Complexity for Euclid's algorithm: O(log10(min(a, b)))" << std::endl;
    std::cout << "Complexity for primeFactorize(worst case): O(min(primeFactorsA.size(), primeFactorsB.size()))." << std::endl;
}

int euclideanGCD(int a, int b){
    int GCD = 1;
    while (a != 0 && b !=0 ){
        if(a > b){
            a = a % b;
        } else {
            b = b % a;
        }
    }
    GCD = a + b;
    return GCD;
}

int euclideanLCM(int a, int b){
    int GCD = euclideanGCD(a,b);
    int LCM;
    LCM = (a * b) / GCD;
    return LCM;
}

int computeGCD(int a, int b) {
    std::vector<int> primeFactorsA = primeFactorize(a);
    std::vector<int> primeFactorsB = primeFactorize(b);
    int GCD = 1;
    int i = 0;
    int j = 0;
    while (i < primeFactorsA.size() &&  j < primeFactorsB.size()){
        if (primeFactorsA[i] == primeFactorsB[j]){
                GCD *= primeFactorsA[i];
                i++;
                j++;
        } else {
            i++;
            j++;
        }
    }
    return GCD;
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

int input(std::string msg) {
    if (!msg.empty()) {
        std::cout << msg << ": ";
    }
    int value;
    std::cin >> value;
    return value;
}
