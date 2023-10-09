#include <iostream>

int euclidGCD(int a,int b){
    
    if (a == 0) {
       return b; 
     }
    if (b == 0) {
       return a;
    }
  
    if( a == b ){
        return a;
    }
    int d = 0;
    if( a > b ){
        d = a - b;
        euclidGCD( d, b);
    } 
    else {
      euclidGCD( b, a ); 
    }
}

int euclidLCM(int a, int b) {
   
    return (a * b) / euclidGCD( a, b );
}

int main() {
    int a,b;
    std::cout<<"Enter num1"<<std::endl;
    std::cin >> a;
    std::cout<<"Enter num2"<<std::endl;
    std::cin >> b;
    std::cout << "GCD is "<< euclidGCD(a, b) <<std::endl;
    std::cout << "LCD is " << euclidLCM(a, b) <<std::endl;
    return 0;
}