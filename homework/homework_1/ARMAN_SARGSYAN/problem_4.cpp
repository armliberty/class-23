#include <iostream>
#include <vector>
#include <cmath>

std::vector<int> primeFactorize(int n)
{
    std::vector<int> ans;
    while (n % 2 == 0){
        ans.push_back(2);
        n = n/2;
    }
    for (int i = 3; i <= std::sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            ans.push_back(i);
            n=n/i;
        }
    }
    if (n > 2){
        ans.push_back(n);
    }
    return ans;
}
void GCD(int num1, int num2){
    std::vector<int> arr1;
    std::vector<int> arr2;
    arr1 = primeFactorize(num1);
    arr2 = primeFactorize(num2);
    
    int result = 1;
    for (int i = 0; i < arr1.size(); i++ ) {
        for (int j = 0; j < arr2.size(); j++ ) {
            if(arr1[i] == arr2[j]){
                result *= arr1[i];
                arr1.erase(arr1.begin() + i);
                arr2.erase(arr2.begin() + j);
            }
        }
    }
    std::cout << result;
}

int main() {
    int num1,num2; 
    std::cin >> num1;
    std::cin >> num2;
    GCD(num1, num2);
    return 0;
}