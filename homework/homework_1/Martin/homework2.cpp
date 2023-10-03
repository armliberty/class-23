#include <cmath>
#include <iostream>
#include <string>
#include <vector>


using IntVector = std::vector<int>;

template <typename T>
T input(std::string msg);

template <typename T>
void print(T value);

std::pair<bool, IntVector> isPrime(int);
IntVector primeFactorize(int);

int computeGCD(int a, int b);
int computeLCM(int a, int b);


int main(){
    // is your input value
    const auto num = input<int>("Input your number");


    return 0;
}

template <typename T>
T input(std::string msg) {
    if (!msg.empty()) {
        std::cout << msg << ": ";
    }
    T value;
    std::cin >> value;

    return value;
}

std::pair<bool, IntVector> isPrime(int n){

    if(n<=1){
        return std::make_pair(false, primeFactorize(n));
    }

    for(int i = 2; i<n/2; i++){
        if(n%i==0){
            return std::make_pair(false, primeFactorize(n));
        }
    }

    return std::make_pair(true, primeFactorize(n));
}

IntVector primeFactorize(int n){
    IntVector results;

     while (n % 2 == 0){
        results.push_back(2);
        n = n/2;
    }
 
    for (int i = 3; i <= sqrt(n); i = i + 2){
        while (n % i == 0)
        {
            results.push_back(i);
            n = n/i;
        }
    }
 

    if (n > 2){
        results.push_back(n);
    }

    return results;
        
}

template <typename T>
void print(T value){
    if (value.first){
         std::cout <<"Is a Prime Number: ";
    }
    else{
        std::cout <<"Is not a Prime Number: ";
    }

    for(int i = 0; i<value.second.size(); i++){
        std::cout << value.second[i]<< " ";
    }
}

int computeGCD(int a, int b){
    int result = 1;
    IntVector aVector = primeFactorize(a);
    IntVector bVector = primeFactorize(b);

    for(int i = 0; i<aVector.size(); i++){
        for(int j = 0; j<bVector.size(); j++){
            if(aVector[i]==bVector[j]){
                result*=aVector[i];
                bVector[j] = -1;
                break;
            }
        }
    }
    return result;
}

int computeLCM(int a, int b){
    return a*b/computeGCD(a,b);
}