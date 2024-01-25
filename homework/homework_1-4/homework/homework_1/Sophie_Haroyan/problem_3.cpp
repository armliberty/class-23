#include <cmath>
#include <iostream>
#include <vector>

bool isPrime(int digit);
std::vector<int> primeFactorize(int digit);

int main(){

    int digit;
    std:: cout << "Input your digit: ";
    std:: cin >> digit;
       
    if(isPrime(digit))
        std:: cout << "Your digit is prime";
    else
        std:: cout << "Digit's factors: \n";
        auto factiorize = primeFactorize(digit);
        for (int i = 0; i < factiorize.size(); ++i) {
            std::cout << factiorize[i] << " ";
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

    std:: cout << "Prime Factorizes: ";

    for(int i = 0; i < commons.size(); ++i){
        if (i == commons.size() - 1){
            std:: cout << commons[i] << std:: endl;
        }
        else {
            std:: cout << commons[i]<<"x";  
        }
    }
    return commons;
}