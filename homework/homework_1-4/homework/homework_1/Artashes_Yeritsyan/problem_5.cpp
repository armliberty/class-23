#include <cmath>
#include <iostream>
#include <vector>

bool isPrime(int digit);
int euclidsGCD(int a, int b);
int euclidsLCM(int a, int b);
int findGcdOrLcm(int firstValue, int secondDigit, bool isGCD);

int main() {

    int a;
    int b;
    std:: cout << "input first digit: ";
    std:: cin >> a;
    std:: cout << "input second digit: ";
    std:: cin >> b;       
    
    std:: cout << "GCD: " << euclidsGCD(a, b) << "\nLCM: " <<  euclidsLCM(a, b) << std::endl;
  
    return 0;   
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

int euclidsGCD(int a, int b) {

    if (a == b){
        return a;
    }
    else if (a > b && (a % b == 0)) {
        return b;
    }
    else if (b > a && (b % a == 0)) {
        return a;
    }
    else if (isPrime(a) || isPrime(b)) {
        return 1;
    }    
    else if (a > b) {        
        return findGcdOrLcm (a, b, true);
    }
    else {
        return findGcdOrLcm (b, a, true);
    }
}

int euclidsLCM(int a, int b) {

    if (a == b){
        return b;
    }
    else if (a > b && (a % b == 0)) {
        return a;
    }
    else if (b > a && (b % a == 0)) {
        return b;
    }
    else if (isPrime(a) && isPrime(b)){
        return a * b;
    }
    else if (isPrime(a) && (b % a == 0)){
        return b;
    }
    else if (isPrime(b) && (a % b == 0)){
        return a;
    }
    else if (a > b) {        
        return findGcdOrLcm (a, b, false);
    }
    else {
        return findGcdOrLcm (b, a, false);
    }
}

int findGcdOrLcm (int firstValue, int secondValue, bool isGCD) {
    int remainder = 0;

    // if (firstValue > secondValue && (firstValue % secondValue == 0)) {
    //     return isGCD ? secondValue : firstValue;
    // }

    int a1 = firstValue;
    int b1 = secondValue;
            
    while (a1 % b1 != 0) {
        remainder = a1 % b1;
        a1 = b1;
        b1 = remainder;
    }
    if(a1 % b1 == 0) {
        return isGCD ? remainder : firstValue * secondValue / remainder;
    }
    else {
        return isGCD ? 1 : firstValue * secondValue;
    }
}
