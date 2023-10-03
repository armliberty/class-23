#include <iostream>
#include <vector>


std::vector<int> primeFactorize(int n) {
    std::vector<int> factors;

    while (n % 2 == 0) {
        factors.push_back(2);
        n /= 2;
    }
    
    for (int factor = 3; factor * factor <= n; factor += 2) {
        while (n % factor == 0) {
            factors.push_back(factor);
            n /= factor;
        }
    }
    
    if (n > 1) {
        factors.push_back(n);
    }
    
    return factors;
}
int computeLCM(int a, int b){
    int lcm = 1;
    bool x = true;
    std::vector<int> aFactors = primeFactorize(a);
    std::vector<int> bFactors = primeFactorize(b);
    for (int i = 0; i < aFactors.size(); i++) {
        for (int j = 0; j < bFactors.size(); j++) {
            if (aFactors[i] == bFactors[j]) {
                lcm *= aFactors[i];
                bFactors[j] = -1; //elimination of duplicates
                x = false;
                break;
            }
        }
        if (x){ 
            lcm *= aFactors[i];
        }
        x = true;
    }
    
    for (int j = 0; j < bFactors.size(); j++) {
        if (bFactors[j] != -1) {
            lcm *= bFactors[j];
        }
    }
    return lcm;
}
int main(){
    int a,b;
    std::cout << "Enter number1 : ";
    std::cin>>a;
    std::cout << "Enter number2 : ";
    std::cin>>b;

    std::cout<<computeLCM(a,b)<<std::endl;
}