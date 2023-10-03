#include <iostream>
#include <vector>
bool isPrime(int);
std::vector<int> primeFactorize(int);
int main()
{
    int dig;
    std::cout<<"dig:";
    std::cin>>dig;
    auto fact=primeFactorize(dig);
    for(int i=0;i<fact.size();++i) {
        std::cout<<fact[i]<<' ';
    }
    std::cout<<std::endl;
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




