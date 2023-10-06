#include <iostream>
#include <vector>

std::vector<int> PrimeFactorize(int);
int computeGCD(int , int );

int main() {
   int a,b,GCD,LCM;
   std::cout<<"a=";std::cin>>a;
   std::cout<<"b="; std::cin>>b;
   std::vector <int> prime_factors;
   GCD=computeGCD(a,b);
   LCM = ( (a*b)/GCD);
   
   std::cout<<"LCM="<<LCM;
   

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

int computeGCD(int a, int b){
    int n;
    std::vector <int> a_prime_factors;
    a_prime_factors = PrimeFactorize(a);
    std::vector <int> b_prime_factors;
    b_prime_factors = PrimeFactorize(b);
    
    int GCD=1, i=0, j=0;
   while(i < a_prime_factors.size() && j < b_prime_factors.size()){
     if(a_prime_factors[i] < b_prime_factors[j]) i++;
     else if(a_prime_factors[i] > b_prime_factors[j]) j++;
     else {
         GCD *= a_prime_factors[i]; i++; j++;
     }
   }
   
   return GCD;
}
