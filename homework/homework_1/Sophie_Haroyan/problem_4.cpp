#include <cmath>
#include <iostream>
#include <vector>

bool isPrime(int digit);
std::vector<int> primeFactorize(int digit);
int computeGCD(int a, int b);
int computeLCM(int a, int b);

int main(){
    
    int a;
    std:: cout << "Input your first digit: ";
    std:: cin >> a;
    int b;
    std:: cout << "Input your second digit: ";
    std:: cin >> b;
       
   if(isPrime(a) && isPrime(b)){
        std:: cout << "Your digits are prime";
        std:: cout << "GCD: 1" << "\nLCM: " << a * b;
   }
    else {
         std:: cout << "GCD: " << computeGCD(a, b);
         std:: cout << "LCM: " << computeLCM(a, b);
    }
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

std::vector<int> primeFactorize(int digit) {

    std::vector<int> commons;
    int half;
    half = digit/2;
    for (int i = half; i>=2; --i) {
        if (digit % i == 0 && isPrime(i))
        {
            commons.push_back(i);
            digit = digit / i;
            i = digit + 1 / 2;
        }
    }
    commons.push_back(digit);
    return commons;
}

int computeGCD(int a, int b) {
    const auto factorize_a = primeFactorize(a);
    
    int gcd = 1;

    for(int i = 0; i < factorize_a.size(); ++i) {
        if (b % factorize_a[i] == 0){
            gcd *= factorize_a[i];
            b = b / factorize_a[i];
        }
    }

    return gcd;
}

int computeLCM(int a, int b) {
    if (isPrime(a) && isPrime(b)) {
        return (a * b);
    }
    else if (isPrime(a) && (b % a == 0)) {
        return (b);
    }
    else if (isPrime(b) && (a % b == 0)) {
        return (a);
    }
    else {
        return ((a * b) / computeGCD(a, b));
    }
}