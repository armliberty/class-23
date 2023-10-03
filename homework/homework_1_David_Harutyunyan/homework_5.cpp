#include <iostream>
#include <cmath>
#include <vector>
#include "Functions.cpp"

int compute_GCD(int a, int b);
int compute_LCM(int a, int b);


int main()
{
   int a,b;
   std::cout<<"a=";
   std::cin>>a;
   std::cout<<std::endl<<"b=";
   std::cin>>b;
   int GCD = compute_GCD(a, b); 
   std::cout<<"GCD="<<GCD<<std::endl;
   int LCM = compute_LCM(a, b);
   std::cout<<"LMC="<<LCM<<std::endl;

   //using header file
   std::cout<<"homework_4's GCD function: "<<computeGCD(a, b)<<std::endl;
   
}

int compute_GCD(int a, int b)
{
    int t;
    int GCD;
    while (b!=0)
        {
            t = b;
            b = a%b;
            a = t;
            GCD = a;
        }
        
    return GCD;
}

int compute_LCM(int a, int b)
{
   int LCM = (a*b)/compute_GCD(a,b);
    return LCM;
}


