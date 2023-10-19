#include <iostream>
#include <cmath>
bool isPrime(int x);

int main() {
    int x;
    std::cout<<"Input x :";
    std::cin>>x;
    isPrime(x);
    return 0;
}

bool isPrime(int x){
    const double tmp=sqrt(x) ;
    int k=2;
    while (k<=tmp){
        if(x%k==0){
            std::cout<<"NO";
            return 0;
        }
        else{k+=1;}    
    }
    std::cout<<"YES";
    return 1;
}