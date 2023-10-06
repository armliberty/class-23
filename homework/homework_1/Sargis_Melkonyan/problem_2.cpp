/*
2. Write a function that check if an integer is prime:
    ```bool isPrime(int);```
*/

#include <iostream>
#include <string>

bool isPrime(int);
int input(std::string);

int main(){
    const auto includ_num = input("number: ");
    
    if(isPrime(includ_num))
        std::cout << includ_num << " is prime"<<std::endl;
    else
        std::cout << includ_num << " is not prime"<<std::endl;

    return 0;
}

int input(std::string msg) {
    int value;
    std::cout << msg ;
    std::cin >> value;

    return value;    
}

bool isPrime(int number){
    if(number <= 1)return false;
    
    int i;
    for(i = 2;i<=(number/2); ++i){
        if(number % i == 0)return false;
    }
    return true;
}