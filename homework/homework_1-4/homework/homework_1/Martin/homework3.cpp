#include <cmath>
#include <iostream>
#include <string>
#include <vector>


using IntVector = std::vector<int>;

template <typename T>
T input(std::string msg);



IntVector primeFactorize(int);

int euclidGCD(int a, int b);
int euclidLCM(int a, int b);

int computeGCD(int a, int b);
int computeLCM(int a, int b);

int main(){
    // is your input values
    const auto num1 = input<int>("Input your first number");
    const auto num2 = input<int>("Input your first number");

    std::cout<<"computeGC: "<<computeGCD(num1,num2)<<std::endl;
    std::cout<<"euclidGCD: "<<euclidGCD(num1,num2)<<std::endl;
    std::cout<<"computeLC: "<<computeLCM(num1,num2)<<std::endl;
    std::cout<<"euclidLCM: "<<euclidLCM(num1,num2)<<std::endl;

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

int euclidGCD(int a, int b){
    int R;
    while ((a % b) > 0){
        R = a % b;
        a = b;
        b = R;
    }

    return b;
}

int euclidLCM(int a, int b){
    return a*b/euclidGCD(a,b);
}