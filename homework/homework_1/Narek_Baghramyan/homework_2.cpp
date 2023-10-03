#include <iostream>

bool isPrime(int);
int input(std::string);

int main(){
    int num ;
    std::cout << "Number = "; std::cin >> num;
    if(isPrime(num))
        std::cout << num << " is prime"<<std::endl;
    else
        std::cout << num << " is not prime"<<std::endl;

    return 0;
}

bool isPrime(int number){
    if(number <= 1)return false;
    
    int i;
    for(i = 2;i<=(number/2); ++i){
        if(number % i == 0)return false;
    }
    return true;
}