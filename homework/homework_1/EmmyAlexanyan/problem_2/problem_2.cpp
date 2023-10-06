#include <iostream>

bool isPrime(int);

int main(){
    int a; bool f=true;
    std::cout<<"a="; std::cin>>a;
    f=isPrime(a);
    if(f == true) std::cout<<a<<" is prime";
    else std::cout<<a<<" is not prime";
    
}

bool isPrime(int a){
    int count=0;
    for(int i=2; i<=a/2; i++)
        if(a % i == 0) count++;
    
    if(count == 0)return true;
    else return false;
};
