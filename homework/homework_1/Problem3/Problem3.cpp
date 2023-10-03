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
void PrintFac(std::vector<int> primeFactors, int num){
    int j = 1;
    int suffix = 1;
    std::cout << "Prime Factors " << num << " = ";
    for (int i = 0; i<primeFactors.size(); i++ ) {
        while(primeFactors[i] == primeFactors[i+j] ){
            ++suffix;
            ++j;
        }
        std::cout<< primeFactors[i]<<"^"<<suffix;
        if ((i+j)!=primeFactors.size()){
            std::cout<< " * ";
        }
        i += j-1;
        suffix = 1;  j = 1;
    }
    std::cout << std::endl;
}
    

int main() {
    int num;
    std::cout << "Enter number : ";
    std::cin >> num;

    PrintFac(primeFactorize(num), num);
    
    return 0;
}
