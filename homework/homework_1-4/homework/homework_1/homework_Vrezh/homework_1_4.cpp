#include <iostream>
#include <vector>
#include <cmath>

std::vector<int> primeFactorize(int n) {
    std::vector<int> ans;
    
    while (n % 2 == 0) {
        ans.push_back(2);
        n = n / 2;
    }
    
    for (int i = 3; i <= std::sqrt(n); i = i + 2) {
        while (n % i == 0) {
            ans.push_back(i);
            n = n / i;
        }
    }
    
    if (n > 2) {
        ans.push_back(n);
    }
    
    return ans;
}

int GCD(int a, int b) {
    std::vector<int> arr1 = primeFactorize(a);
    std::vector<int> arr2 = primeFactorize(b);
    
    int result = 1;
    
    for (int i = 0; i < arr1.size(); i++) {
        for (int j = 0; j < arr2.size(); j++) {
            if (arr1[i] == arr2[j]) {
                result *= arr1[i];
                arr1.erase(arr1.begin() + i);
                arr2.erase(arr2.begin() + j);
                i--; 
                break;
            }
        }
    }
    
    return result;
}

int LCM(int a, int b) {
    int gcd = GCD(a, b);
    return (a * b) / gcd;
}

int main() {
    int a, b;
    std::cout << "Enter num1 "<<std::endl;
    std::cin >> a;
    std::cout <<"Enter num2"<<std::endl;
    std::cin>> b;
    
    if (a <= 0 || b <= 0) {
        std::cout << "Enter positive integers." << std::endl;
        return 1;
    }
    
    int gcd_result = GCD(a, b);
    int lcm_result = LCM(a, b);
    
    std::cout << "GCD: " << gcd_result << std::endl;
    std::cout << "LCM: " << lcm_result << std::endl;
    
    return 0;
}
