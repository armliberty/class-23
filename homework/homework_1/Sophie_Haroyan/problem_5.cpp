#include <cmath>
#include <iostream>
#include <vector>

bool isPrime(int digit);
std:: vector<int> euclid(int a, int b);

int main(){

    int a;
    int b;
    std:: cout << "input first digit: ";
    std:: cin >> a;
    std:: cout << "input second digit: ";
    std:: cin >> b;
       
    const auto GCDandLCM = euclid(a, b);
    std:: cout << "GCD: " << GCDandLCM[0] << "\nLCM: " << GCDandLCM[1];

return 0;
   
}

bool isPrime(int digit) {

    int root;
    root = sqrt(digit);

    for (int i = 2; i <= root; ++i) {
        if (digit % i == 0) {
            return false;           
        }
    }
    return true;
}

std::vector<int> euclid(int a, int b) {
    std::vector<int> GCDandLCM;
    int gcd;
    int lcm;

    if (a > b && (a % b == 0)){
        gcd = b;
        lcm = a;
        GCDandLCM.push_back(gcd);
        GCDandLCM.push_back(lcm);
        return GCDandLCM;
    }
    
     if (b > a && (b % a == 0)){
        gcd = a;
        lcm = b;
        GCDandLCM.push_back(gcd);
        GCDandLCM.push_back(lcm);
        return GCDandLCM;
    }
    
    if (a == b){
        gcd = a;
        lcm = a;
        GCDandLCM.push_back(a);
        GCDandLCM.push_back(b);
       return GCDandLCM;
    }

    if (isPrime(a) && isPrime(b)){
        GCDandLCM.push_back(1);
        GCDandLCM.push_back(a * b);
       return GCDandLCM;
    }

    else if (isPrime(a) && (b % a == 0)){
        GCDandLCM.push_back(b / a);
        GCDandLCM.push_back(b);
       return GCDandLCM;
    }
    else if (isPrime(b) && (a % b == 0)){
    
        GCDandLCM.push_back(a / b);
        GCDandLCM.push_back(a);
       return GCDandLCM;
    }
    
    
    int remainder = 0;
        int a1=a;
        int b1=b;
        if (a > b) {        
            while (a1 % b1 != 0) {
                remainder = a1 % b1;
                a1 = b1;
                b1 = remainder;
            }
            if(a1 % b1 == 0) {
                gcd = remainder;
                lcm = (a * b)/gcd;
                GCDandLCM.push_back(gcd);
                GCDandLCM.push_back(lcm);
                return GCDandLCM;
            }                 
            else {
                gcd=1;
                lcm = a * b;
                GCDandLCM.push_back(gcd);
                GCDandLCM.push_back(lcm);
                return GCDandLCM;
            }
        }
        else {
            while (b1 % a1 != 0) {
                remainder = b1 % a1;
                b1 = a1;
                a1 = remainder;    
            }
            if (b1 % a1 == 0){
                gcd = remainder;
                lcm = (a * b)/gcd;
                GCDandLCM.push_back(gcd);
                GCDandLCM.push_back(lcm);
                return GCDandLCM;
            }
            else {
                gcd = 1;
                lcm = a * b;
                GCDandLCM.push_back(gcd);
                GCDandLCM.push_back(lcm);
                return GCDandLCM;
            }        
        }
        return GCDandLCM;
}
