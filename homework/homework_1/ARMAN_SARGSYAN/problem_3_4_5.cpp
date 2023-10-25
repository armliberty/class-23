#include <iostream>
#include <vector>
#include <cmath>

bool isPrime(int n) {
    if (n <= 1) {
        return false; 
    }
    if (n % 2 == 0 || n % 3 == 0) {
        return false;
    }
    for (int i = 5; i * i <= n; i++ ) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

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



int main() {
    int num;
    std::cin >> num;
    if (isPrime(num)) {
        std::cout << num << "is prime." << std::endl;
    } else {
        std::cout << num << "is not prime." << std::endl;
    }
    auto ans = primeFactorize(num);
    for(int i = 0; i<ans.size();i++){
        std::cout<<ans[i]<<" ";
    }
    std::cout<<std::endl;

    return 0;
}