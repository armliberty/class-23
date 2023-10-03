#include <iostream>
#include <cmath>
int EuqlideanGCD(int a,int b);
int computeLCM(int a,int b);
int main() {
    int a,b;
    std::cout<<"a:";
    std::cin>>a;
    std::cout<<"b:";
    std::cin>>b;
    std::cout<<"GCD is "<<EuqlideanGCD(a,b)<<std::endl;
    std::cout<<"LCM is "<<computeLCM(a,b)<<std::endl;
}
int EuqlideanGCD(int a,int b) {
    int rem,div;
    if(a>b) {
        if(a%b==0) {
            return b;
        }
        while((a%b)!=0) {
        rem=a%b;
        a=b;
        b=rem;
    }
    }
    else {
        if(b%a==0) {
            return a;
        }
        while((b%a)!=0) {
            rem=b%a;
            b=a;
            a=rem;
        }
    }
    return rem;
}
int computeLCM(int a,int b) {
    int lcm=a*b/EuqlideanGCD(a,b);
    return lcm;
}





