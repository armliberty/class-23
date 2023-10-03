#include <iostream>
#include <vector>
bool isPrime(int);
std::vector<int> primeFactorize(int);
int computeGCD(int a, int b);
int computeLCM(int a, int b);
int main()
{
    int a,b;
    std::cout<<"a:";
    std::cin>>a;
    std::cout<<"b:";
    std::cin>>b;
    std::cout<<"LCM is "<<computeLCM(a,b)<<std::endl;
    std::cout<<"GCD is "<<computeGCD(a,b)<<std::endl;
}
bool isPrime(int dig)
{
    bool res=true;
    for(int i=2;i<dig/2;++i)
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
int computeGCD(int a, int b)
{
    auto a_fact=primeFactorize(a);
    auto b_fact=primeFactorize(b);
    int GCD=1;
    for(int i=0;i<a_fact.size();++i) {
        for(int j=0;j<b_fact.size();++j) {
            if(a_fact[i]==b_fact[j]) {
                GCD*=a_fact[i];
                a_fact[i]=b_fact[j]=-1;
            }
        }
    }
    return GCD;
}
int computeLCM(int a, int b)
{
    auto a_fact=primeFactorize(a);
    auto b_fact=primeFactorize(b);
    int LCM=1;
    for(int i=0;i<a_fact.size();++i) {
        for(int j=0;j<b_fact.size();++j) {
            if(a_fact[i]==b_fact[j]) {
                LCM*=a_fact[i];
                a_fact[i]=b_fact[j]=-1;
            }
        }
    }
    for(int i=0;i<a_fact.size();++i) {
        if(a_fact[i]!=-1) {
            LCM*=a_fact[i];
        }
    }
    for(int i=0;i<b_fact.size();++i) {
        if(b_fact[i]!=-1) {
            LCM*=b_fact[i];
        }
    }
    return LCM;
}


