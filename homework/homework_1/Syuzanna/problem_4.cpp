#include <cmath>
#include <iostream>
#include <vector>


int computeGCD(int a, int b);
int computeLCM(int a, int b);
std::vector<int> primeFactorize(int);
bool isPrime(int dig);


int main(){
    int a,b;
    std::cout<<"a:" ;
    std::cin>>a;
    std::cout<<"b:" ;
    std::cin>>b;
    std::cout<<"computeGCD:" << computeGCD( a, b) << std::endl;
    std::cout<<"computeLCM:" << computeLCM( a, b) << std::endl;
    return 0;
    
}


bool isPrime(int dig)
{
    bool res=true;
    for(int i=2;i<dig;++i)
    {
        if (dig%i==0)
        {
            res=false;
            break;
        }
    }
    return res;
}


std::vector<int> primeFactorize(int dig)
{
    std::vector<int> fact;
    int rem, i=2;
    if(dig<=1) {
        std::cout<<"It's not prime";
        return fact;
    }
    if (isPrime(dig)) {
        fact.push_back(dig);
        return fact;
    }
    else {
        while (i<=dig) {
            rem=dig%i;
            if (isPrime(i) && rem==0) {
                fact.push_back(i);
                dig=dig/i;
                i=2;
            }
            else if (isPrime(i) && rem!=0) {
                ++i;
            }
            else {
                ++i;
            }
        }
    }
    return fact;
}


int computeGCD(int a, int b){
    auto A=primeFactorize(a);
    auto B=primeFactorize(b);
    int GCD=1; 
    int aa=A.size();
    int bb=B.size();
    for(int i=0; i<aa; ++i){
        for(int j=0; j<bb; ++j)
            if(A[i]==B[j])   
                {
                    GCD*=A[i];
                    A[i]=B[j]=-1;
                } 
    }            
    return GCD;        
            
}        

int computeLCM(int a, int b){
     auto A=primeFactorize(a);
    auto B=primeFactorize(b);
    int LCM=1; 
    int aa=A.size();
    int bb=B.size();
    for(int i=0; i<aa; ++i){
        for(int j=0; j<bb; ++j)
            if(A[i]==B[j])   
                {
                    LCM*=A[i];
                    A[i]=B[j]=-1;
                }           
    }     
    for(int i=0; i<aa; ++i)
        if(A[i] != -1)
            LCM*=A[i];         
    for(int j=0; j<bb; ++j)
        if(B[j] != -1)
            LCM*=B[j];               
    return LCM;
}