#include <iostream>
#include <math.h>
#include <vector>

std::vector<int> PrimeFactorize(int);

int main() {
   int a;
   std::cout<<"a="; std::cin>>a;
   std::vector <int> prime_factors;
   prime_factors = PrimeFactorize(a);
   for(int i=0; i < prime_factors.size(); i++)
    std::cout<<prime_factors[i]<<" ";
   

    return 0;
}

std::vector<int> PrimeFactorize(int a){
    std::vector<int> prime_factors;
    for(int i=2;i<=a/2;i++){
        while(a%i == 0)
          {prime_factors.push_back(i); a = a/i;}
    }   
    if(a>2) prime_factors.push_back(a);
    return prime_factors;
};
