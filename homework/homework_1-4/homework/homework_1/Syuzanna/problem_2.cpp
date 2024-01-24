#include <iostream>
bool isPrime(int);
int main()
{
    int dig;
    do {
        std::cout<<"dig:";
        std::cin>>dig;        
    }
    while(dig<=1);
    bool res=isPrime(dig);
    if(res){
        std::cout<<"It's prime"<<std::endl;
    }
    else{
        std::cout<<"it's not prime"<<std::endl;
    }
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