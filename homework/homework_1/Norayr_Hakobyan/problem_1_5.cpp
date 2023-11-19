#include <cmath>
#include <iostream>
#include <vector>

int computeGCD(int a, int b);
int computeLCM(int a, int b);
std::vector<int> Prime_Factorize(int n);

int main() 
{
   int a , b;
   std::cout << "a="; std::cin >> a;
   std::cout << "b="; std::cin >> b;
   int gcd = computeGCD(a, b); 
   std::cout << "GCD = " << gcd << std::endl;
   int lcm = computeLCM(a, b);
   std::cout << "LCM = "<< lcm << std::endl;  
}

int computeGCD(int a, int b) 
{ 
  int k;
  while ((a % b) > 0) 
  {
    k = a % b;
    a = b;
    b = k;
  }
  return b;
}


int computeLCM(int a, int b) 
{
    int lcm = (a * b) / computeGCD(a,b);
    return lcm;
}

std::vector<int> Prime_Factorize(int n) {
    std::vector<int> vect;

    while(n % 2 == 0) {
        n = n / 2;
        vect.push_back(2);   
    }

    for(int i = 3; i <= std::sqrt(n); i+=2) {
        while(n % i == 0) {
            vect.push_back(i);
            n = n / i;
        } 
    } 

    if(n >= 2) {
        vect.push_back(n);
    }

    return vect;
}

