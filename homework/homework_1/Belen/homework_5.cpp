#include <iostream>

int computeGCD(int a,int b){
    int t;
    while(b != 0){
        t=b;
        b=a%b;
        a=t;
    }
    return a;
}

int main(){
    int num1,num2;
        std::cout << "First number ";
        std::cin >> num1;

        std::cout << "Second number ";
        std::cin >> num2;

        std::cout<<"GCD :   "<< computeGCD(num1,num2);
        std::cout<<"LCM :  "<< (num1*num2)/computeGCD(num1,num2);

   
}