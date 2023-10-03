#include <cmath>
#include <iostream>

bool isPrime(int digit);

int main(){

    int digit;
    std:: cout << "Input your digit: ";
    std:: cin >> digit;

    isPrime(digit);
    
    if(isPrime(digit))
        std:: cout << "Your digit is prime";
    else
        std:: cout << "Try again";
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
