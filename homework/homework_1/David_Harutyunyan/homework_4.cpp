#include <iostream>
#include <cmath>
#include <vector>

int computeGCD(int a, int b);
int computeLCM(int a, int b);
std::vector<int> primeFactorize(int n);

int main()
{
   int a,b;
   std::cout<<"a=";
   std::cin>>a;
   std::cout<<std::endl<<"b=";
   std::cin>>b;
   int GCD = computeGCD(a, b); 
   std::cout<<"GCD="<<GCD<<std::endl;
   int LCM = computeLCM(a, b);
   std::cout<<"LMC="<<LCM<<std::endl;
}

int computeGCD(int a, int b)
{
    std::vector<int> afactorize = primeFactorize(a);
    std::vector<int> bfactorize = primeFactorize(b);

    int GCD = 1, i = 0, j = 0;

        while(i < afactorize.size() && j < bfactorize.size())   
            {
                if(afactorize[i] < bfactorize[j]) 
                    {
                        i++;
                    }
                else if(afactorize[i] > bfactorize[j]) 
                    {
                        j++;
                    }
                else if(afactorize[i] == bfactorize[j])
                    {
                        GCD*=afactorize[i]; 
                        i++;
                        j++;
                    }
            }
            return GCD;
}

int computeLCM(int a, int b)
{
   int LCM = (a*b)/computeGCD(a,b);
    return LCM;
}


std::vector<int> primeFactorize(int n)
{
    std::vector<int> vec;

    while(n%2==0)
        {
            n/=2;
            vec.push_back(2);
        }  
    for(int i = 3; i<sqrt(n); i+=2)
        {
           while(n%i==0)
            {
                vec.push_back(i);
                n = n/i;
            } 
        } 

    if(n>2)
        {
            vec.push_back(n);
        }
            return vec;
}