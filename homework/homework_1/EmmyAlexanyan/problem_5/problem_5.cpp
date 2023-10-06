#include <iostream>

int main(){
    int a, b;
    std::cout<<"a="; std::cin>>a;
    std::cout<<"b="; std::cin>>b;
    
    while(a != 0 && b != 0){
        if(a>b) a = a % b;
        else b = b % a;
    }
    
    std::cout<<"GCD="<<(a+b);
    
    return 0;
}
