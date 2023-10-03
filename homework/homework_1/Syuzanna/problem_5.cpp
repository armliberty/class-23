#include <cmath>
#include <iostream>

int Euclidean_GCD(int a, int b ,int &GCD);
int LCM(int a, int b ,int GCD);

int main(){
        int a,b, GCD;
        std::cout<<"a:" ;
        std::cin>>a;
        std::cout<<"b:" ;
        std::cin>>b;
        std::cout<<"Euclidean_GCD:" << Euclidean_GCD(a, b , GCD) << std::endl;
        std::cout<<"LCM:" << LCM(a, b, GCD) << std::endl;
        return 0;
}


int Euclidean_GCD(int a, int b ,int &GCD){
    int r;
    GCD=1;
    if(a>b)
        while(a % b!= 0){
            r=a % b;
            a=b;
            b=r;
        }
    else
        while(b % a!= 0){
            r=b % a;
            b=a;
            a=r;
        }
    GCD=r;
    return GCD;
}

int LCM(int a, int b ,int GCD){
         int E_LCM=(a*b)/GCD;
         return E_LCM;
}